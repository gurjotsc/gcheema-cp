#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
                     

void solve() {
    ll n; cin >> n;
    ll c1, c2;
    c1 = n/3;
    c2 = c1;
    if(c1 + (2*c2) < n-1) ++c2;
	else if (c1 + (2*c2) != n) ++c1;
    cout << c1 << " " << c2;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    };
}