#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
                     
int solve() {
    int a, b; cin >> a >> b;
    int res = b-a;
    
    for(int i = a; i < b; ++i) res = min(res, ((i|b) - b) + 1 + (i-a));

    int maxBitsB = log2(b)+1;
    int maxBitsCurr = maxBitsB;
    int i = b;
    while(maxBitsCurr <= maxBitsB) {
        res = min(res, ((i|a)-b+1));
        ++i;
        maxBitsCurr = log2(i)+1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}