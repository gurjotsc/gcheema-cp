class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        if(n == 1) return 1;  
        int res = 0;
        for(int i = 0; i < 24; ++i) {
            int curr = 0;
            int bitCheck = pow(2,i);
            for(auto j : candidates)
                if(j&bitCheck) curr++;
            res = max(res, curr);
        }
        return res;
    }
};