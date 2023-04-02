class Solution {
public:
    string interpret(string s) {
        string res;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'G') res.push_back('G');
            else if(s[i+1] == ')') {
                res.push_back('o');
                ++i;
            }
            else {
                res.push_back('a');
                res.push_back('l');
                i += 3;
            }
        }
        return res;
    }
};