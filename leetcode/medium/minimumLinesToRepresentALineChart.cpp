class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        sort(stockPrices.begin(), stockPrices.end());
        if(n <= 2) return n - 1;
        int res = 1;
        for(int i = 2; i < n; ++i) {
            auto prev = stockPrices[i-1];
            auto pPrev = stockPrices[i-2];
            auto curr = stockPrices[i];
            res += (((long long)(prev[1]-pPrev[1])*(long long)(curr[0]-prev[0])) != ((long long)(curr[1] - prev[1])*(long long)(prev[0]-pPrev[0])));  
        }
        return res;
    }
};