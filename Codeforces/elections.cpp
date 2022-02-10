#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        
        //a
        if(max(b, c) > a) {
            cout << max(b,c) - a + 1 << " ";
        }
        else if (max(b, c) == a) cout << 1 << " ";
        else cout << 0 << " ";

        //b
        if(max(a, c) > b) {
            cout << max(a,c) - b + 1 << " ";
        }
        else if (max(a, c) == b) cout << 1 << " ";
        else cout << 0 << " ";

        //c
        if(max(a, b) > c) {
            cout << max(a,b) - c + 1;
        }
        else if (max(a, b) == c) cout << 1;
        else cout << 0;

        cout << endl;
    }
}