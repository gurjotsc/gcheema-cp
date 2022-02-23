#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int l = -1, r = -1;
        string s; cin >> s;
        vector<int> a(26);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'a') {
                l = i-1;
                r = i+1;
                a[0] = 1;
                break;
            }
        }
        if(r == -1) {
            cout << "NO" << endl;
            continue;
        }

        for(int i = 1; i < 26; ++i) {
            if(l < 0 && r >= s.size()) break;
            else if(l >= 0 && s[l] == 'a' + i && !a[i]) {
                --l;
                a[i] = 1;
            }
            else if(r < s.size() && s[r] == 'a' + i && !a[i]) {
                ++r;
                a[i] = 1;
            }
            else break;
        }

        if(l < 0 && r >= s.size()) cout << "YES" << endl;
        else cout << "NO" << endl;

        
    }
}