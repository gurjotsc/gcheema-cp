class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int z = 0, o = 0, res = 0;
        bool check = false;

        for(int i = 0; i < n; ++i) {
            if(!check) {
                if(s[i] == '0') ++z;
                else {
                    check = true;
                    o = 1;
                }
            }
            else {
                if(s[i] == '1') ++o;
                else {
                    check = false;
                    cout << z << " " << o << "\n";
                    res = max(res, min(z,o)*2);
                    z = 1;
                    o = 0;
                }
            }
        }

        if(o) res = max(res, min(z,o)*2);
        return res;
    }
};