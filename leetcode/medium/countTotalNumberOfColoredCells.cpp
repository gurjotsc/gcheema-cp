class Solution {
public:
    vector<long long> res;
    Solution() {
        int cnt = 0;
        res.resize(1e5+1,0);
        res[1] = 1;
        for(int i = 2; i < res.size(); ++i, ++cnt) {
            res[i] = res[i-1] + (4*cnt) + 4;
        }
    }
    
    long long coloredCells(int n) {return res[n];}
};