class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1, res = 0;
        int correctGuesses = 0;
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> guessMap(n);
        vector<int> parents(n); //used to store parents of a nodes assuming 0 is the root
        
        function<void(int, int)> fillParents = [&](int node, int parent) { //assuming root is 0
            parents[node] = parent;
            for(auto child : adj[node]) if(child != parent) 
                fillParents(child, node);
        };

         function<void(int, int, int)> dfs = [&](int node, int parent, int prevCorrectGuesses) {
            int curr = prevCorrectGuesses;
            if(guessMap[parent].count(node)) --curr;
            if(guessMap[node].count(parent)) ++curr;
            res += (curr >= k);
            for(auto& child : adj[node]) if(child != parent)
                dfs(child, node, curr);
        };

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto& g : guesses)
            guessMap[g[0]].insert(g[1]);

        //find how many guesses in guesses are correct assuming root is 0
        fillParents(0, -1);
        for(int i = 1; i< n; ++i)
            correctGuesses += guessMap[parents[i]].count(i);
        res += (correctGuesses >= k); //0 as a root works
        
        for(auto& child : adj[0])
            dfs(child, 0, correctGuesses);
        
        return res;
    }
};