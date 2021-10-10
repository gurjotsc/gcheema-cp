class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        //store everything in 1D vector nums
        for(auto i : grid){
            for(auto j : i) {
                nums.push_back(j);
            }
        }
        //sort nums to find the median
        //this will be the middle value and we can use it to see what the minimal operations             count it
        sort(nums.begin(), nums.end());
        int median = (nums[(nums.size()-1) / 2]);
        int res = 0;
        //iterate through every number and see how many times you need to add or subtract x
        //increment res by that count
        for(auto i : nums){
            int difference = abs(i - median);
            //if the difference is not possible to acheive with x then you know that there is               no solution (since other differences are satisfied with x and need to approach                 the median)
            if(difference%x) return -1;
            else res += (difference/x);
        }
        return res;


    }
};
