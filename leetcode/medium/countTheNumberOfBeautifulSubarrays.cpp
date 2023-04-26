using ll = long long;
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll, ll> pre;
        ll res = 0, curr = 0;
        pre[0] = 1;
        
        for(const auto& i : nums) {
            curr ^= i;
            res += pre[curr]++;
        }

        return res;
        
    }
};