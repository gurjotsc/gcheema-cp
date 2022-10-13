class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string res = "";
        for(int i = n-1; i >= 0; --i) {
            if (s[i] == '#') {
                i -= 2;
                res = (char)('a'+(stoi(s.substr(i, 2)))-1) + res;
            }
            else res = (char)('a'+(stoi(s.substr(i,1))-1)) + res;
        }
        return res;
    }
};