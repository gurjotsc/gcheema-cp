#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        bool flag = false;
        //any balanced subtring will have a point in which s[i] != s[i+1]
        for(int i = 0; i < n-1; ++i) {
            if(s[i] != s[i+1]) {
                cout << i+1 << " " << i+2 << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << "-1 -1" << endl;
    }
}