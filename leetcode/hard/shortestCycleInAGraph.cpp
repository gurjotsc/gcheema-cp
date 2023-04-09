class Solution {
public:
    int n;
    int bfs(const vector<vector<int>>& adj, int start) {
        vector<int> dist(n, -1);
        vector<int> parents(n, -1);
        queue<int> q;
        int res = INT_MAX;

        q.push({start});
        dist[start] = 0;
        
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(const auto& i : adj[curr]) {
                if(dist[i] == -1) {
                  q.push({i});
                  dist[i] = dist[curr]+1;
                  parents[i] = curr;
                }
                else if(parents[i] != curr && parents[curr] != i){ //seperate parents
                    res = min(res, dist[curr]+dist[i]+1);
                }
            }
        }

        return res;
    }
    int findShortestCycle(int nn, vector<vector<int>>& edges) {
        n = nn;
        vector<vector<int>> adj(n);
        int res = INT_MAX;
        for(const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(int i = 0; i < n; ++i) if(adj[i].size()>1)
            res = min(res, bfs(adj, i));

        return (res != INT_MAX) ? res : -1;
    }
};