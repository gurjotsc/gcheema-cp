class Solution {
public:
    int mod = 1e9+7;
    using ull = unsigned long long;
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<ull, ull>> v;
        priority_queue<ull, vector<ull>, greater<>> pq;
        for(ull i = 0; i < n; ++i) v.push_back({e[i], s[i]});
        sort(rbegin(v), rend(v)); //sorted descending. Largest efficiency first
        
        ull currSpeed = 0, res = 0;
        for(ull i = 0; i < n; ++i) {
            if(pq.size() >= k) {
                currSpeed -= pq.top();
                pq.pop();
            }
            pq.push(v[i].second);
            currSpeed += v[i].second;
            res = max(res, currSpeed*v[i].first);
        }

        return res%mod;
    }
};