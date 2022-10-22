class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = firstList.size(), m = secondList.size();
        while(i < n && j < m) {
            auto curri = firstList[i], currj = secondList[j];
            int x = max(curri[0], currj[0]), y = min(curri[1], currj[1]);
            if(x <= y) res.push_back({x,y});
            if(y == curri[1]) ++i;
            else ++j;
        }
        return res;
    }
};