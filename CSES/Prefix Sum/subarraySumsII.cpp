#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long n, x; cin >> n >> x;
    vector<long long> prefix(n);
    unordered_map<long long, long long> m;
    cin >> prefix[0];
    m[prefix[0]] = 1;
    for(long long i = 1; i < n; ++i) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    long long ans = 0;
    for(long long i : prefix) {
        ans += m[i-x];
        ++m[i];
    }

    cout << ans << "\n";

}
