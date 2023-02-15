class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int res = 0;
        for(int i = 0; i < n; ++i){
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<double, int> m;
            for(int j = i+1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                double slope = (x1 != x2) ? (double)(y1-y2)/(x1-x2) : DBL_MAX;
                ++m[slope];
                res = max(res, m[slope]+1);
            }
        }
        return res;
    }
};