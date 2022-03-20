#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll n;

ll bestCandidate(vector<ll>& vals, ll check) {
    ll best = inf, idx = -1;
    for(ll i = 0ll; i < n; ++i) {
        if(best > abs(check-vals[i])) {
            best = abs(check-vals[i]);
            idx = i;
        }
    }
    return idx;
}

ll solve() {
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll res = inf;
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    vector<ll> casesA1 = {0ll, bestCandidate(b, a[0]), n-1};
    vector<ll> casesAN = {0ll, bestCandidate(b, a[n-1]), n-1};

    for(auto i : casesA1) {
        for(auto j : casesAN) {
            ll check = (abs(a[0] - b[i]) + abs(a[n-1] - b[j]));
            //b[0] not accounted for
            if(i > 0 && j > 0) check += abs(a[bestCandidate(a, b[0])] - b[0]);
            //b[n-1] not accounted for
            if(i < n-1 && j < n-1) check += abs(a[bestCandidate(a, b[n-1])] - b[n-1]);

            res = min(res, check);

        }
    }

    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}