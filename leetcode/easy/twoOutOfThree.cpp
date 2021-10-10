class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool count[3][101] = {false}; //One element for each possible nume[i] (the max of an                                         //elem is 100)
                                      //we need 101 because 0 can't be an element
                                      //three rows for each nums
        vector<int> res;
        //if the number is found, then update the number in the respective row to true
        for(int i : nums1) count[0][i] = true;
        for(int i : nums2) count[1][i] = true;
        for(int i : nums3) count[2][i] = true;
        //iterate through count to see if two are found
        //for all rows, and for all i in count, if i is found to be true in two or more arrays         //(hence > 1) then push back to result
        for(int i = 1; i < 101; ++i) {
            if(count[0][i] + count[1][i] + count[2][i] > 1)  res.push_back(i);
        }
        return res;
    }
};
