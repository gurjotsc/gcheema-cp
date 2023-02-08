class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        vector<int> lessFromL(n);
        vector<int> lessFromR(n);
        lessFromL[0] = -1; 
        lessFromR[n-1] = n;

        for(int i = 1; i < n; ++i) {
            int p = i-1;
            while(p >= 0 && heights[p] >= heights[i]) p = lessFromL[p];
            lessFromL[i] = p;
        }
        for(int i = n-2; i >= 0; --i) {
            int p = i+1;
            while(p < n && heights[p] >= heights[i]) p = lessFromR[p];
            lessFromR[i] = p;
        }

        for(int i = 0; i < n; ++i)
            res = max(heights[i]*(lessFromR[i]-lessFromL[i]-1), res);

        return res;
    }
};