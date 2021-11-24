#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
#define ll long long
int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n; cin >> n;
    vector<int> w(2*n);
    int ans = 0;

    for(int i = 0; i < 2*n; ++i) cin >> w[i];
    sort(w.begin(), w.end());

    int maxDiff = 0;
    for(int i = 0; i < (2*n) - 1; ++i) {
        w[i] = abs(w[i] - w[i+1]);
        maxDiff = max(maxDiff, w[i]);
    }
    w[2*n - 1] = 0;
    sort(w.begin(), w.end());

    for(int i = 1; i < 2*n - 2; ++i) ans += w[i];

    cout << ans;
1 2 3 4
1 1 1 0
0 1 1 1


3
305 139 205 406 530 206
139 205 206 305 406 530
75  1   99  99  124 0
0   1   75  99  99  124


  166  66 201  124 324 0
  0   66 124  166 201 324


}
