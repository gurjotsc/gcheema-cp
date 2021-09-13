class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        //Declare the dp of the previous one and the one two behind the current one
        //These store the optimal solution up to that point
        int prev1 = 0;
        int prev2 = 0;
        //Iterate through the entire vector and update the optimal solutions
        for(auto n : nums) {
            int temp = prev1; //Temp to hold prev1 cuz we are gonna update it
            prev1 = max(prev2 + n, prev1); //Either you can add the current houses money or not rob the current house. Update the solution based off of what earns you more money.
            prev2 = temp; //Update prev2
        }
        return prev1; //Return the optimal solution
    }
};
