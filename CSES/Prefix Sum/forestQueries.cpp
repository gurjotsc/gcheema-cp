#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, q; cin >> n >> q;
    vector<vector<int>> prefix(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            char temp; cin >> temp;
            prefix[i][j] = (temp == '.') ? prefix[i][j-1] : prefix[i][j-1] + 1;
        }
    }

    for(int i = 0; i < q; ++i) {
        int ans = 0;
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        ans = (prefix[y1][x2] - prefix[y1][x1-1]) + (prefix[y2][x2] - prefix[y2][x1-1]);
        cout << ans << "\n";
    }


}
