#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    int res = 0;
    vector<int> bills = {100, 20, 10, 5, 1};
    for(auto i : bills) {
        res += (n/i);
        n %= i;
        if(!n) break;
    }
    cout << res;
}