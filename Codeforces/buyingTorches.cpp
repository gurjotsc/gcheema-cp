#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
ll solve() {
    ll x, y, k; cin >> x >> y >> k;
    ll res = 0ll;
    double totalSticksNeeded = (y*k)+k-1; //start off with 1 stick so minus 1
    res += ceil(totalSticksNeeded/(x-1)); //minus 1 because you need to trade in a stick
    res += k; //add k trades to turn sticks to coals
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
    

}