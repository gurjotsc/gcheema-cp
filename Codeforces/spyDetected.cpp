#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     

int solve() {
    int n; cin >> n;
    vector<int> a(n);

    for(auto& i : a) cin >> i;

    for(int i = 0; i < n; ++i) {
        if(!i && a[i+1] == a[i+2] && a[i] != a[i+1]) return 0+1;
        if(i < n-1 && a[i-1] == a[i+1] && a[i] != a[i+1]) return i+1;
        else if(i == n-1) return i+1;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t ; cin >> t;
    while(t--) cout << solve() << "\n";
}