using ll = long long;
class Solution {
public:
    int n, m;
    ll solve(vector<int>& nums, vector<ll>& pre, ll target) {
        ll idx = lower_bound(begin(nums), end(nums), target) - begin(nums);
        ll sumL = pre[idx], sumR = pre[n] - pre[idx];
        return (ll)abs(target*idx-sumL)+(ll)abs(target*(n-idx)-sumR);
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        n = nums.size(), m = q.size();
        vector<ll> res;
        sort(begin(nums), end(nums));
        vector<ll> pre(n+1);
        for(int i = 0; i < n; ++i) pre[i+1] = pre[i]+nums[i];

        for(ll target : q) res.push_back(solve(nums, pre, target));
        return res;
    }
};