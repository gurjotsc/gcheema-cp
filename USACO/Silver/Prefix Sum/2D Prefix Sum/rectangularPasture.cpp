#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n, k; cin >> n >> k;
    vector< vector<int> > dp(n + 1, vector<int>(n+1));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; i <= n; ++j) {
            cin >> dp[i][j];
        }
    }
}
