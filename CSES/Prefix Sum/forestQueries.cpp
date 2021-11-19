#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            char temp; cin >> temp;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + (temp == '*') - dp[i-1][j-1];
        }
    }

    for(int i = 0; i < q; ++i) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        int above = dp[y1-1][x2];
        int left = dp[y2][x1-1];
        int add = dp[y1-1][x1-1]; //you subtract this region twice
        cout << dp[y2][x2] - above - left + add << "\n";
    }


}
