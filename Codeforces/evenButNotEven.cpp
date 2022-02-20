#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string num; cin >> num;
        if(n == 1) cout << "-1" << endl;
        else {
            string res = "";
            for(int i = 0; i < n; ++i) {
                if(!res.size() && (num[i]-'0')%2 && i != n-1) res += num[i];
                else if(res.size() && (num[i]-'0')%2) {
                    res += num[i];
                    cout << res << endl;
                    break;
                }
                else if (i == n-1) cout << "-1" << endl;
            }
        }
    }
}