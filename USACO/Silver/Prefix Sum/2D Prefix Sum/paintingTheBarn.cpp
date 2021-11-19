#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int n, k; cin >> n >> k;

    vector<vector<int> > dp(1001, vector<int> (1001));

    while(n--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ++dp[y1][x1];
        ++dp[y2][x2];
        --dp[y2][x1];
        --dp[y1][x2];
    }

    int ans = 0;
    for(int i = 0; i < 1001; ++i) {
        for(int j = 0; j < 1001; ++j) {
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            if(i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
            ans += dp[i][j] == k;
        }
    }

    cout << ans;
}
