#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    vector<ll> prefix(n+1);
    vector<ll> sizes(n+1, LLONG_MIN);
    vector<ll> res(n+1, LLONG_MIN);

    cin >> a[0];
    prefix[0] = 0ll;
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i-1];
    }
    prefix[n] = prefix[n-1] + a[n-1];

    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < i; ++j) {
    //         ll mx = LLONG_MIN;
    //         mx = max(mx, prefix[i] - prefix[j]);
    //         k[i-j] = max(mx, k[i-j]);
    //     }
    // }
    for(int k = n; k >= 0; --k) {
        int l = 0, r = k;
        ll mx = LLONG_MIN;
        while(r <= n) {
            mx = max(mx, prefix[r] - prefix[l]);
            ++l; ++r;
        }

        for(int j = k; j >= 0; --j) sizes[j] = max(sizes[j], mx);
    }
    ll mx = sizes[0];
    res[0] = sizes[0];
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, res[i-1]);
        res[i] = max(mx, sizes[i]+(x*i));
    }

    for(auto& i : res) cout << i << " ";

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}