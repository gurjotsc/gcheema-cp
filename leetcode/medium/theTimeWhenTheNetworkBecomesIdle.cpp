class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adjacencyMatrix(n);
        vector<int> time(n, -1); //time for each node to reach master server
        int res = 0;

        for(auto i : edges) {
            //node 0 leads to 1 and vice versa
            adjacencyMatrix[i[0]].push_back(i[1]);
            adjacencyMatrix[i[1]].push_back(i[0]);
        }

        queue<int> q; //bfs queue
        q.push(0); //start bfs at the master
        time[0] = 0; //time for master is just zero

        //bfs
        while(!q.empty()) {
            int node = q.front(); q.pop();

            for(int i : adjacencyMatrix[node]) { //look through every child of node
                //if the node hasn't been visited, then the time it takes to reach the master                     server is just how long it takes to reach the parent node + 1;
                if(time[i] == -1) {
                    time [i] = time[node] + 1;
                    q.push(i); //the reason we don't push if time[i] != -1  is because that                                   node has already been visited, hence bfs already found the                                     shortest path to that node.
                }
            }
        }

        //iterate through all nodes
        for(int i = 0; i < n; ++i) {
            if(patience[i] != 0) { //prevent divide by 0;
                //how long it takes to recieve a response is the time to the master and back                     time[i] * 2
            //divide by patience[i] to get how many messages were sent again
            int extraMessages = (time[i] * 2 - 1)/patience[i];
            int lastTimeOut = (patience[i] * extraMessages); //what time the last message cme                                                                out
            int lastReplyIn = (time[i] * 2) + lastTimeOut; //when the last one came out + how                                                              long it takes to receive a reply                                                              for the last one
            res = max(res, lastReplyIn);
            }
        }
        return res + 1; //the next second is when the network is idle
    }
};
