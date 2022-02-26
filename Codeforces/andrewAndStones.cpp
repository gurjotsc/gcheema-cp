#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        ll res = 0;
        for(auto& i : a) cin >> i;

        if(n == 3 && a[1]%2) {
            cout << -1 << endl;
            continue;
        }

        int i = 1; 
        while(i < n-1 && a[i] == 1) ++i;
        if(i == n-1) {
            cout << -1 << endl;
            continue;
        }

        for(int i = 1; i < n-1; ++i) {
            res += ((a[i]%2) ? ((a[i]+1)/2) : (a[i]/2));
        }
        cout << res << endl;
    }
}