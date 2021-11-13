#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x; cin >> n >> x;
    vector<ll> prefix(n);
    map<ll, ll> m;
    cin >> prefix[0];
    m[prefix[0]] = 1;
    for(ll i = 1; i < n; ++i) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    ll ans = 0;
    for(ll i : prefix) {
        ans += m[i-x];
        ++m[i];
    }

    cout << ans << "\n";

}
