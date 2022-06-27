class Solution {
public:
    int n;
    vector<int> par;
    int L, R;
    int dfs(const vector<vector<int>>& adj, 
            vector<int>& dp, 
            const vector<int>& nums, 
            vector<int>& comp,
            int r, int p, int c)
    {    
        dp[r] = nums[r];
        par[r] = p;
        comp[r] = c;
        for(int v : adj[r]) {
            if (v == p || comp[v] != -1) continue;
            if ( (r == L && v == R) || (r == R && v == L) ) continue;
            dp[r] ^= dfs(adj, dp, nums, comp, v, r, c);
        }
        return dp[r];
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int ans = 1e9;
        n = nums.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n-1; ++i) {
            par.assign(n, -1);
            L = edges[i][0], R = edges[i][1];
            vector<int> dp(n, 0), comp(n, -1);
            int c = 0;
            for (int u = 0; u < n; ++u)
                if (comp[u] == -1)
                    dfs(adj, dp, nums, comp, u, u, c++);
            
            array<int,3> x{};
            for (int u = 0; u < n; ++u)
                x[ comp[u] ] ^= nums[u];
            
            for(int j = i+1; j < n-1; ++j) {
                int l = edges[j][0], r = edges[j][1];
                if (par[l] == r) swap(l,r);
                auto res = x;
                res[ comp[l] ] ^= dp[r];
                res[2] = dp[r];
                sort( begin(res), end(res) );
                ans = min(ans, res[2] - res[0]);
            }
        }
        return ans;
    }
};