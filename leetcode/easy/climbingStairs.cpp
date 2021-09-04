class Solution {
public:
    int ans = 0;
    int climbStairs(int n) {
        if(!n) return ans;
        if(n == 1) return ++ans;
        ans += 2;
        if(n == 2) return ans;
        int prev2 = 1;
        int prev = 2;
        for(int i = 2; i < n; ++i) {
            ans = prev2 + prev;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};
