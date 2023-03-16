class Solution {
public:
    enum SCORE {DRAW, MOUSE, CAT};

    vector<array<int, 3>> parents(const vector<vector<int>>& g, int m, int c, int t) {
        vector<array<int, 3>> res;
        
        //t can only be either 1 or 2
        if(t == 2)
            for(int m2 : g[m])
                res.push_back({m2, c, 1});
        else
            for(int c2 : g[c]) if(c2)
                res.push_back({m, c2, 2});

        return res;
    }

    int catMouseGame(vector<vector<int>>& g) {
        int N = g.size();
        vector<vector<vector<int>>> dp(50, vector<vector<int>>(50, vector<int>(3))); //stores state of mouse, cat, and whose turn it is
        vector<vector<vector<int>>> degree(50, vector<vector<int>>(50, vector<int>(3)));
        
        for(int m = 0; m < N; ++m)
            for(int c = 0; c < N; ++c) {
                degree[m][c][1] = g[m].size();
                degree[m][c][2] = g[c].size();
                for(int i : g[c]) if(!i) {
                    degree[m][c][2]--;
                    break;
                }
            }

        
        queue<array<int, 4>> q;
        for(int i = 0; i < N; ++i)
            for(int t : {1,2}) {
                dp[0][i][t] = MOUSE;
                q.push({0, i, t, MOUSE});
                if(i > 0) {
                    dp[i][i][t] = CAT;
                    q.push({i, i, t, CAT});
                }
            }

        while(!q.empty()) {
            auto[i, j, t, s] = q.front(); q.pop(); //i and j are mouse and cat location, t is whose turn, s is the color of the node (the score)
            if(t != 1 && t != 2) {
                cout << i << j << t;
            }
            for(auto [ii, jj, tt] : parents(g, i, j, t)) {
                if(dp[ii][jj][tt] == DRAW) {
                    if(tt == s) {
                        dp[ii][jj][tt] = s;
                        q.push({ii, jj, tt, dp[ii][jj][tt]});
                    }
                    else {
                        --degree[ii][jj][tt];
                        if(!degree[ii][jj][tt]) {
                            dp[ii][jj][tt] = (tt == 2) ? 1 : 2;
                            q.push({ii, jj, tt, dp[ii][jj][tt]});
                        }
                    }
                }
            }
        }


        
            
        return dp[1][2][1];
    }
};