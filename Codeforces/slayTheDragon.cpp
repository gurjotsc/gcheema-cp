#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sum = 0;

ll solve(vector<ll>& A) {
    ll x, y;
    cin >> x >> y;
    auto it = lower_bound(A.begin(), A.end(), x);
    if (it == A.begin()) {
        ll send = *it;
        ll keep = sum - send;
        return max(0ll, y - keep);
    }

    if (it == A.end()) {
        ll send = *prev(it);
        ll keep = sum - send;
        return max(0ll, y - keep) + max(0ll, x - send);
    }

    ll sendPrev = *prev(it);
    ll keepPrev = sum - sendPrev;
    ll send = *(it);
    ll keep = sum - send;
    //             upgrade defense        upgrade attack
    ll a = max(0ll, y - keepPrev) + max(0ll, x - sendPrev);
    ll b = max(0ll, y - keep) + max(0ll, x - send);
    return min(a, b);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cin >> m;
    for(auto i : A) sum += i;
    for(int i = 0; i < m; ++i) {
        cout << solve(A) << "\n";
    }
    return 0;

}
