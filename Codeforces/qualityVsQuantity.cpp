#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
string solve() {
    int n; cin >> n;
    vector<ll> a(n);
    // ll m1 = 10e6, m2 = 10e6;
    // ll mx = 0ll;
    
    for(auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    // for(int i = 0; i <= (n/2); ++i) b += a[i];
    // for(int i = (n/2) + 1; i < n; ++i) r += a[i]; 
    int i = 1, j = n-1;
    ll l = a[i] + a[0];
    ll r = a[j];
    
    while(i < j) {
        if(l < r) return "YES";
        l += a[++i];
        r += a[--j];
    }

    return "NO";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;

    while(t--) cout << solve() << "\n";
}

// 10
// 14 15 15 15 19 16 14 18 16 10
// 10 14 14 15 15 15 16 16 18 19
// 6
// 10 10 16 11 12 3