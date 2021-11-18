#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n; cin >> n;
    vector<long long> prefix(n+1);
    long long minNum = 0;
    long long maxNum = 0;

    for(int i = 1; i <= n; ++i) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
        minNum = min(minNum, prefix[i]);
        maxNum = max(maxNum, prefix[i]);
    }

    cout << maxNum - minNum;
}
