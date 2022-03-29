class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> preReqCnt(n+1);
        vector<vector<int>> graph(n+1);
        int res = 0;
        
        //creates graph
        for(auto& i : relations) graph[i[0]].push_back(i[1]);
        //Counts all the prereqs for each course
        for(auto& i : graph) 
            for(auto& x : i) ++preReqCnt[x];
        
        //Finds all sources in the graph and pushes them to the q
        queue<int> q;
        for(int i = 1; i <= n; ++i) 
            if(!preReqCnt[i]) q.push(i);
        
        //Holds max distance to get to i because you need to complete the slowest path there (due to needing to complete all prereqs before taking it)
        vector<int> dist(n+1);
        //fill sources with their starting time
        for(int i = 1; i <= n; ++i) dist[i] = (!preReqCnt[i]) ? time[i-1] : 0;
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            //Update the time of all children for curr
            for(auto& child : graph[curr]) {
                --preReqCnt[child];
                dist[child] = max(dist[child], dist[curr]+time[child-1]);
                //you can topsort the next node if all prereqs are completed
                if(!preReqCnt[child]) q.push(child);
            }
        }
        
        for(auto& i : dist) res = max(res, i);
        
        return res;
        
    }
};