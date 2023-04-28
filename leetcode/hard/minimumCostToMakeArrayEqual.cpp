using ll = long long;
class Solution {
public:
    ll n;
    ll getCost(vector<int>& nums, vector<int>& cost, long long target) {
        ll res = 0;
        for(int i = 0; i < n; ++i) 
            res += abs(nums[i]-target)*cost[i];
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        n = nums.size();
        ll lo = *min_element(begin(nums), end(nums));
        ll hi = *max_element(begin(nums), end(nums));

        while(lo < hi) {
            ll mid = lo + ((hi-lo)/2);

            ll fx = getCost(nums, cost, mid);
            ll fx1 = getCost(nums, cost, mid+1);

            if(fx < fx1) hi = mid;
            else lo = mid+1;
        }

        return getCost(nums, cost, hi);
    }
};