class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[2], e[1]});
            // adj[e[1]].push_back({e[2], e[0]});
        }
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[2], e[1]});
        // adj[e[1]].push_back({e[0], e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, int> m;
        pq.push({0, node1});
        while(!pq.empty()) {
            auto [cost, x] = pq.top(); pq.pop();
            m[x] = cost;
            if(x == node2) return cost;
            for(auto e : adj[x]) if(!m.count(e.second) || m[e.second] > cost+e.first)
                pq.push({(unsigned long long)cost+e.first, e.second});
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */