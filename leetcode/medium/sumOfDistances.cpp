using ll = long long;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> res(n);
        map<int, vector<int>> m;
        for(int i = 0; i < n; ++i) m[nums[i]].push_back(i);
        for(auto it = begin(m); it != end(m); ++it) {
            ll pre = 0;
            ll total = 0;
            for(auto i : it->second) total += i;
            for(int i = 0; i < it->second.size(); ++i) {
                int idx = it->second[i];
                ll post = total-pre-idx;

                res[idx] += idx*(ll)i;
                res[idx] -= pre;
                res[idx] += post;
                res[idx] -= idx*(ll)(it->second.size()-i-1);

                pre += idx;
            }
        }
        return res;
    }
};