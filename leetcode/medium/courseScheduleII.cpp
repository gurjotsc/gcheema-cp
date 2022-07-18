class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> m;
        vector<int> in(n);
        vector<int> res = {};
        for (auto& i : p) {
            if(m.count(i[1])) m[i[1]].push_back(i[0]);
            else m[i[1]] = {i[0]};
            in[i[0]] += 1;
        }
        queue<int> q;
        for(int i = 0; i < n; ++i) 
            if(!in[i]) {
                q.push(i);
                res.push_back(i);
            }
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            for(auto i : m[curr]) {
                in[i]--;
                if(!in[i]) {
                    q.push(i);
                    res.push_back(i);
                }
            }
        }
        if(res.size() == n) return res;
        return {};
        
        
    }
};