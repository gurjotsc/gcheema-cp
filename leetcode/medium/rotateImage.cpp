class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //iterate through (n+1) / 2 since if its odd we want to iterate one more than n / 2
        //here we are iterating through columns
        for(int i = 0; i < (n + 1) / 2; ++i) {
            //iterate through n / 2 since we want to round down it its odd (else we'd be doing one too many)
            //here we are iterating through rows (backwards with n - 1 - j)
            for(int j = 0; j < n / 2; ++j) {
                //store what at j index behind n and column i
                int temp = matrix[n - 1 - j][i];
                //matrix of column i and n - 1 - j = the ith column from the right and the same row
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]; //Matrix
                //From here on out we conitnue the process by going one corner back (counter-clockwise) until we get to the last one
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
