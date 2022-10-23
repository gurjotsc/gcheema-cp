class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int i = 0, j = 0;
        string res;
        while(i < n && j < m) {
            if((i%2) == (j%2)) res += word1[i++];
            else res += word2[j++];
        }
        return res + ((i<n) ? word1.substr(i,n) : word2.substr(j,m));
    }
};