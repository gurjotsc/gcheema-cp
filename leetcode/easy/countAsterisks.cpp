class Solution {
public:
    int countAsterisks(string s) {
        int n = s.size(), res = count(begin(s), end(s), '*');
        int l = find(begin(s), end(s), '|') - begin(s);
        int r = find(begin(s)+l+1, end(s), '|') - begin(s);
        while(l != n) {
            cout << l << " " << r << " \n";
            for(int i = l+1; i < r; ++i) res -= (s[i] == '*');
            l = find(begin(s)+r+1, end(s), '|') - begin(s);
            r = find(begin(s)+l+1, end(s), '|') - begin(s);
        }
        return res;
    }
};