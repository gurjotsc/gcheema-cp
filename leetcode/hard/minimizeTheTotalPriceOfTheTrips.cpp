class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        vector<int> count(n);
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int totalCost = 0; //of all trips
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<bool(int, int, int)> dfs = [&](int node, int end, int parent) {
            if(node == end) return true;

            for(auto& i : adj[node]) {
                if(i == parent) continue;
                if(dfs(i, end, node)) {
                    ++count[i];
                    totalCost += price[i];
                    return true;
                }
            }
            return false;
        };

        function<int(int, int, int)> dp = [&](int node, int par, bool parentReduced) {
            if(par != -1) {
                if(parentReduced && dp1[node][par] != -1) 
                    return dp1[node][par];
                if(!parentReduced && dp2[node][par] != -1) 
                    return dp2[node][par];
            }
            int res = 0;
            if(parentReduced) res = count[node]*(price[node]/2);
            
            for(int i : adj[node]) if(i != par) {
                if(!parentReduced) //if the parent wasn't reduced then you can either reduce the current one or not (which means we can pass in true and false for the neighbor)
                    res += max(dp(i, node, true), dp(i, node, false));
                else //if the parent is reduced, then you don't reduce the current one and pass in false for dp since the neighbor's parent (the current node) wasn't reduced
                    res += dp(i, node, false);
            }

            if(par != -1) {
                if(parentReduced) dp1[node][par] = res;
                else dp2[node][par] = res;
            }

            return res;
        };

        for(auto t : trips) {
            ++count[t[0]];
            totalCost += price[t[0]];
            dfs(t[0], t[1], -1);
        }

        int res = totalCost;
        for(int i = 0; i < n; ++i) {
            res = min(res, totalCost - dp(i, -1, true)); //can't reduce this one
            res = min(res, totalCost - dp(i, -1, false)); //can reduce this one
        }

        return res;
    }
};