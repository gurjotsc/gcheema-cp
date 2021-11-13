#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n; cin >> n;
    vector<ll> prefix(n);
    cin >> prefix[0];
    unordered_map<ll, int> m;

    int ans = 0;
    for(int i = 1; i < n; ++i) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    for(int i = 0; i < n; ++i) {
        prefix[i] %= 7;
        if(m.find(prefix[i]) != m.end()) m[prefix[i]] = i;
        else m[prefix[i]] = i;
    }

    for(int i = 0; i < n; ++i) {
        ans = max(ans, m[prefix[i]] - i);
    }
    //if(!ans) ++ans;

    cout << ans;


}
