#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll solve() {
    ll l, r, a; cin >> l >> r >> a;
    ll comp1 = (r/a) + (r%a);
    ll comp2 = r - r%a - 1;
    if(comp2 < l) return comp1;
    comp2 = (comp2/a) + (comp2%a);
    return max(comp1, comp2);
}  
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll t; cin >> t;
    while(t--) cout << solve() << "\n";
}