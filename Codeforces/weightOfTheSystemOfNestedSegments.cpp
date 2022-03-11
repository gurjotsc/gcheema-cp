#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

bool comp(vector<ll> a, vector<ll> b) {return a[1] < b[1];}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> w;
    map<ll, int> idxs;
    ll total = 0ll;
    for(int i = 0; i < m; ++i) {
        ll pos, weight; cin >> pos >> weight;
        w.push_back({weight, pos});
        idxs[pos] = i;
        total += weight;
    }

    sort(w.begin(), w.end());
    for(int i = m-1; i >= 2*n; --i) {
        total -= w[i][0];
        w.pop_back();
    }
    cout << total << "\n";
    sort(w.begin(), w.end(), comp);

    ll i = 0ll, j = w.size()-1;
    while(i<j) cout << idxs[w[i++][1]]+1 << " " << idxs[w[j--][1]]+1 << "\n";


}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;

    while(t--) {
        solve();
        cout << "\n";
    }
}