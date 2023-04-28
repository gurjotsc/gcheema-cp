class Solution {
public:
    vector<int> nums;
    vector<int> dp;
    int n, k;

    int solve(int i) {
        if( i>= n) return 0;
        //The minimum for dp[i] never changes once its set because dp[i] is only concerned witht the elements that appear after i so we can just return it if its set.

        if(dp[i] != -1) return dp[i]; 
        vector<int> m(n,0); //we can use a vector instead of a map because nums[i] < nums.length (see constraints)
        int cnt = 0, res = INT_MAX;

        //lets assume we split at j (meaining j is the final element of our left subarray)
        //we literally test every possible split and track the minimum across all splits and possibilities.
        for(int j = i; j < n; ++j) {
            ++m[nums[j]];
            if(m[nums[j]] == 2) cnt += 2;
            else if(m[nums[j]] > 2) ++cnt;

            res = min(res, solve(j+1)+cnt+k); 
        }
        return dp[i] = res;
    }

    int minCost(vector<int>& nnums, int kk) {
        nums = nnums;
        n = nums.size();
        k = kk;
        dp.resize(n, -1);

        return solve(0);
    }
};