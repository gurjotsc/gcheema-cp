class Solution {
public:
    bool hasCycle(int i, unordered_map<int, vector<int>>& m, vector<int>& visited) {
        if(visited[i] == -1) return true;
        if(visited[i] == 1) return false;
        visited[i] = -1;
        for(auto& x : m[i]) 
            if(hasCycle(x, m, visited)) return true;
        visited[i] = 1;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> m;
        for (auto& i : p)
            if(m.count(i[1])) m[i[1]].push_back(i[0]);
            else m[i[1]] = {i[0]};
        
        //three state:
        //1 = done this node
        //0 = haven't done this node
        //-1 = doing this node
        vector<int> visited(n, 0); 
        for(int i = 0; i < n; ++i) 
            if(hasCycle(i, m, visited)) return false;
        return true;
    }
};