class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string res(n, ' ');

        //if lcp[i][j] then res[i] == res[j] (need to start with same char)
        char c = 'a'-1;
        for(auto i = 0; i < n; ++i){
            if(res[i] != ' ') continue;
            if(++c > 'z') return "";
            for(int j = i; j < n; ++j)
                if(lcp[i][j]) res[j] = c;
        }

        //check to make sure that lcp[i][j] == lcp[i+1][j+1]+1
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int check = (i+1 < n && j+1 < n) ? lcp[i+1][j+1] : 0; 
                if(res[i] == res[j]) check += 1;
                else check = 0;

                if(lcp[i][j] != check) return "";
            }
        }
        return res;
    }
};