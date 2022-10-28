class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size(), res = 0;
        for(int i = 0; i <= n-k; ++i) res += (stoi(s.substr(i,k)) && (!(num%stoi(s.substr(i,k)))));
        return res;
    }
};