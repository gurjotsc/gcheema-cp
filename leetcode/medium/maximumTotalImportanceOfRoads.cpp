class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<long long, int>> numConnections(n);
        for(auto& r : roads) {
            numConnections[r[0]].first++;
            numConnections[r[1]].first++;
        }
        
        for(int i = 0; i < n; ++i) numConnections[i].second = i;
        sort(numConnections.begin(), numConnections.end());
        
        long long res = 0;
        vector<long long> imp(n);
        for(auto int i = n-1; i >= 0; --i) imp[numConnections[i].second] = n--;
        for(auto& r : roads) res += (imp[r[0]]+imp[r[1]]);
        return res;
        
        
    }
};