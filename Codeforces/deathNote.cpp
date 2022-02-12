#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n+1);
    for(int i = 1; i < n+1; ++i) cin >> a[i];
    for(ll i = 1; i < n+1; ++i) {
        a[i] += a[i-1]; //keeps a running total

        if(i == 1) cout << a[i]/m;
        else cout << (a[i]/m) - (a[i-1]/m);
        if(i < n) cout << " ";
        else cout << endl;
    }
}