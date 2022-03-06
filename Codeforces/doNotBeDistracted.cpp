#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
string solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<bool> seen(26);

    for(int i = 0; i < n; ++i) {
        if(seen[s[i]-'A'] && s[i-1] != s[i]) return "NO";
        else seen[s[i] - 'A'] = true;
    }

    return "Yes";

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t ; cin >> t;
    while(t--) cout << solve() << "\n";
}