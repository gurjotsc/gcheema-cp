#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
                     
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, l, k; cin >> n >> l >> k;
    vector<int> d(n);
    vector<int> a(n);
    vector<vector<int>> dp (n, vector<int>(k+1));
    for(auto& i : d) cin >> i;
    for(auto& i : a) cin >> i;

    dp[0][0] = 0;
    for(int i = 1; i < n; ++i) dp[i][0] = dp[i-1][0] + (a[i-1]*(d[i] - d[i-1]));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= k; ++j) {
            if(j >= i) break;

        }
    }


}