#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n; cin >> n;
    vector<ll> prefix(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    ll ans = prefix[1], minSum = prefix[0];
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, prefix[i] - minSum); //choses the max out of our ans and what our curr ans is
        minSum = min(minSum, prefix[i]); //minSum stores the smallest number we have seen so far
    }

    cout << ans;
}
