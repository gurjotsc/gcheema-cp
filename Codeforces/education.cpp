#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll c; cin >> c;
        ll tugs = 0, res = INT_MAX, curr = 0, days = 0;
        vector<ll> a(n);
        vector<ll> b(n-1);
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n-1; ++i) cin >> b[i];
        for(ll i = 0; i < n; ++i) {
            ll d = max(0ll, c-curr);
			res = min(res, days + ((d+a[i])-1)/a[i]);
			d = max(0ll, b[i] - curr);
			ll temp = ((d+a[i]-1)/a[i]);
			curr += temp*a[i] - b[i];
			days += temp+1;
        }
        cout << res << endl;
    }


}
