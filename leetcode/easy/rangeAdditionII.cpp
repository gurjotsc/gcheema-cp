class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
            //Actual Solution
        if(!ops.size()) return m*n;
        int minA = INT_MAX;
        int minB = INT_MAX;
        
        for(auto& o : ops) {
            minA = min(minA, o[0]);
            minB = min(minB, o[1]);
        }
        
        return minA*minB;
        
        //Prefix Range Sum Practice
        //This MLEs but I'm pretty sure it would work
//         if(!ops.size()) return m*n;
//         vector<vector<int>> M (m+1, vector<int>(n+1, 0));
//         for(auto& o : ops) {
//             ++M[0][0];
//             --M[o[0]][0];
//             --M[0][o[1]];
//         }
        
//         int mx = INT_MIN;
//         int res = 0;
//         int startSum = 0;
//         for(int i = 0; i < m; ++i) {
//             startSum += M[i][0];
//             int currSum = startSum;
//             if(currSum > mx) {
//                 mx = currSum;
//                 res = 1;
//             }
//             for(int j = 1; j < n; ++j) {
//                 currSum += M[i][j];
//                 if(currSum > mx) {
//                     mx = currSum;
//                     res = 1;
//                 }
//                 else if (currSum == mx) ++res;
//             }
//         }
        
//         return res;
    }
};