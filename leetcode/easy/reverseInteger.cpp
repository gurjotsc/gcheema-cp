class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        if(!x) return ans;
        while(x) {
            int store = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && store > 7)) return 0;
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && store < -8)) return 0;
            ans = (ans * 10) + store;
        }
        return ans;
    }
};
