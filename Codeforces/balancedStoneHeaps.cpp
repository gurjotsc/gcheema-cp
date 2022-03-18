#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll n;
vector<ll> h;

bool check(ll x) {
    vector<ll> hNew = h;
    for(ll i = n-1; i >= 2; --i) {
        if(hNew[i] < x) return false;
        ll d = (min(h[i], hNew[i]-x)/3);
        hNew[i-1] += d;
        hNew[i-2] += 2*d;
    }
    if(hNew[0] >= x && hNew[1] >= x) return true;

    return false;
}

ll solve() {
    cin >> n;
    h.resize(n);
    ll mx = 0ll;
    for(auto& i : h) {
        cin >> i;
        mx = max(mx, i);
    }

    ll lo = 0, hi = mx;
    while(lo < hi) {
        ll mid = hi - ((hi-lo)/2);
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }

    return lo;


}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}   