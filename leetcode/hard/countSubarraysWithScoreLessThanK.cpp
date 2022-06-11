using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        vector<ll> pre(n+1, 0);
        ll res = 0;
        for(int i = 1; i <= n; ++i) pre[i] = (pre[i-1] + nums[i-1]);
        int l = 0, r = 1;
        while(r <= n && l <= n) {
            if((pre[r] - pre[l])*(r-l) < k) res += (r-l);
            else {
                while((pre[r] - pre[l])*(r-l) >= k && l <= n) ++l;
                res += (r-l);
            }
            ++r;
        }
        return res;
      
    }
};