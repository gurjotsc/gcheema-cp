class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp (n + 1);
        dp[0] = 0;
        //an even number has the rightmost bit equal to 0, while odds have 1
        //because of this, divding any even number by 2 will have the same amount of ones
        //(shifting the binary representation 1 space to the right is the same thing as diving the whole number by 2 (in an even number, shifting by 1 to the right drop the right most 0 and the resulting number has the same number of ones in the representation as the original number)) this shift is represented by dp[i/2]
        //if its an odd number, taking the integer division of 2 and adding 1 will give you how many ones are in that number. this is represented by i&1 (wether or not i is odd)
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i/2] + (i&1);
        }
        return dp;
    }
};
