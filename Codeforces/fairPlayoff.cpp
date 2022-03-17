#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


string solve() {
    int s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;

    if(max(s1, s2) > min(s3, s4) && min(s1, s2) < max(s3, s4)) return "YES";
    else return "NO";
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}