class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int m = land.size();
        int n = land[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if((!i || !land[i-1][j]) && (!j || !land[i][j-1]) && land[i][j] == 1) {
                    vector<int> temp(4);
                    int x = i; int y = j;
                    temp[0] = i; temp[1] = j;
                    while(x < m && land[x][j]) ++x;
                    while(y < n && land[i][y]) ++y;
                    --x; --y;
                    temp[2] = x; temp[3] = y;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
