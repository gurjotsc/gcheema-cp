class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res;
        vector<vector<pair<int, int>>> graph(n);
        queue<pair<int, int>> q; //stores the starting index you are going to BFS at and the                                        color
        vector<vector<int>> cost (n, (vector<int>(2, -1)));
        //for each node you want to stare the cost it takes to get from there to n-1. At each index here we have another vector<int> that stores two elements, representing the cost to reach the end node from that node for both red and blue

        //for the following two for loops, create a graph (adjacency matrix) that goes throught red and blue respectivley. Each index in graph has a vector of pairs that represents all the nodeds connected to the node at that index and the color
        for (auto& edge : red_edges) graph[edge[0]].push_back({edge[1], 0}); //last zero represents                                                                             red
        for(auto& edge : blue_edges) graph[edge[0]].push_back({edge[1], 1});//last one represents                                                                             blue
        //^^by using 0 and 1 for the colors, we can index by 0 and 1 as well when we check in cost. Red will always be at index 0 and blue at 1 (i.e cost[i][0] is the cost of a node to get to n-1 using its red path)


        q.push({0, 0}); //red start
        q.push({0, 1}); //blue start
        cost[0] = {0,0}; //cost is zero if n is zero
        while(!q.empty()) {
            auto[bfsIndex, color1] = q.front(); q.pop(); //structure binding
            for(auto[exploreNode, color2] : graph[bfsIndex]) { //bfs at bfsIndex
                //if we already know the cost from here or if its the same color then no need                   to do anything
                if(cost[exploreNode][color2] != -1 || color1 == color2) continue;
                //the cost it takes for bfsIndex to reach n-1 plus 1
                cost[exploreNode][color2] = 1 + cost[bfsIndex][color1];
                q.push({exploreNode, color2});
            }
        }
        for(auto& c : cost) {
            sort(c.begin(), c.end()); //whichever color in cost has the shorter length it at                                            index 0
            res.push_back((c[0] != -1) ? c[0] : c[1]); //takes the smaller value if valid
        }
        return res;
    }
};
