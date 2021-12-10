class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> res (n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                res[i][j] = min(rowSum[i],colSum[j]);
                //you know that the sum of rowSum and colSum are the same. Because of this you can greedily pick the min of rowSum[i] and colSum[j] for each node and decrement both by the chosen value (meaning that the rest of the cells in the chosen row or column will be 0) This way the last node where i = j = n-1 must have the same value for rowSum[i] and colSum[j]
                //in a case where you have a massive colSum but small row sum say colSum = {400, 1,2} and rowSum = {1,2,400} then the last row first column would be 397
                //since you decrement both the row and the column, each row and column will eventually get chosen when we reach their respective i and j
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;

    }
};
