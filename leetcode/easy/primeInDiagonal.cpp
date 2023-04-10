class Solution {
public:
    bool isPrime(int n) {
        for(int i = 2; i <= sqrt(n); ++i) 
            if(!(n%i))
                return false;
        return n > 1;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(isPrime(nums[i][i])) res = max(res, nums[i][i]);
            if(isPrime(nums[nums.size()-i-1][i])) res = max(res, nums[nums.size()-i-1][i]);
        }
        return res;
    }
};