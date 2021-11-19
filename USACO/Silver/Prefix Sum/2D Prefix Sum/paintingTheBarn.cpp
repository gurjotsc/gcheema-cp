#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int n, k; cin >> n >> k;

    vector<vector<int>> prefix(1001, vector<int> (1001));

    while(n--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ++prefix[y1][x1];
        ++prefix[y2][x2];
        --prefix[y2][x1];
        --prefix[y1][x2];
    }

    int ans = 0;
    for(int i = 0; i < 1001; ++i) {
        for(int j = 0; j < 1001; ++j) {
            if(i > 0) prefix[i][j] += prefix[i-1][j];
            if(j > 0) prefix[i][j] += prefix[i][j-1];
            if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            ans += prefix[i][j] == k;
        }
    }

    cout << ans;
}
