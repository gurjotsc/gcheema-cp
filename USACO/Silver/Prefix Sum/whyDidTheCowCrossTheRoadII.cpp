#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, b;
    cin >> n >> k >> b;

    vector<int> prefix(n+1);
    vector<int> broken(n+1);
    int ans = INT_MAX;
    for(int i = 0; i < b; ++i) {
        int idx; cin >> idx;
        broken[idx] = 1;
    }

    for(int i = 1; i < n+1; ++i) prefix[i] = prefix[i-1] + broken[i];

    //how many lights you got to fix between i and the i+kth light
    for(int i = 0; i < n-k+1; ++i) ans = min(ans, prefix[i+k] - prefix[i]);

    cout << ans;
}
