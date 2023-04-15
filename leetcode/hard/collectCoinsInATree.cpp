class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        int res = n-1;
        vector<vector<int>> adj(n);
        if(find(begin(coins), end(coins), 1) == end(coins)) return 0;

        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> leaf;
        for(int i = 0; i < n; ++i) if(adj[i].size() == 1)
            leaf.push_back(i);

        vector<int> coinLeaves; //going to store all leaves with coins since we're removing leaves with no coins
        for(auto l : leaf) {
            if(coins[l]) {
                coinLeaves.push_back(l);
                continue;
            }
            while(!coins[l] && adj[l].size() == 1) {
                int p = adj[l][0];
                adj[p].erase(find(begin(adj[p]), end(adj[p]), l));
                adj[l].clear();
                --res;
                l = p;
            }
            if(adj[l].size() == 1) coinLeaves.push_back(l);
        }

        leaf.clear();
        
        for(auto l : coinLeaves) {
            if(!adj[l].size())
                continue;
            int p = adj[l][0];
            coins[p] = 1;
            adj[p].erase(find(begin(adj[p]), end(adj[p]), l));
            adj[l].clear();
            --res;
            if(adj[p].size() == 1) leaf.push_back(p);
        }
        
        res -= leaf.size();
        res *= 2;
        return max(res, 0);
    }
};