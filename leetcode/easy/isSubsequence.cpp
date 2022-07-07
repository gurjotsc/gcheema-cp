class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int i = 0;
        int j = 0;
        for(int x = 0; x < n; ++x, ++j) 
            if(s[i] == t[j]) i++;
        return i == s.size();
    }
};