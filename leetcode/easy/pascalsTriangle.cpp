class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1); //starting row
        if(numRows == 1) return ans;
        ans[1].push_back(1); //second row
        ans[1].push_back(1); //second row
        if(numRows == 2)return ans;
        numRows -= 2; //since we nalready set the first two rows
        int i = 1; //we add from the ith row to create the i + 1th node
        while(numRows--) { //iterate numRows times
            int s = ans[i].size();
            ans[++i].push_back(1); //start with one
            for(int j = 0; j < s - 1; ++j) { //iterate through the entire previous row
                ans[i].push_back(ans[i-1][j] + ans[i-1][j+1]); //add the index you're on and the next index to                                                                  create the value of the corresponding node                                                                    below it
            }
            ans[i].push_back(1); //last value
        }
        return ans;
    }
};
