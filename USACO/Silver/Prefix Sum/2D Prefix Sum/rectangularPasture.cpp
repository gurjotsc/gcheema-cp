#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n; cin >> n;
    vector< vector<ll> > prefix(10e9, vector<ll>(10e9));

    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        prefix[x][y] = 1;
    }



    ans = pow(2,n);

}
