#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> res;
    if(k == n-1){
        if(n == 4) {
            cout << -1 << "\n";
            return;
        }
        res.push_back({1, 3});
        res.push_back({n-2, n-1});
        int l = 2, r = n-3;
        while(l<r) {
            if(l == 3) res.push_back({0, r});
            else res.push_back({l, r});
            ++l; --r;
        }
    }
    else if(!k) {
        int l = 0, r = n-1;
        while(l<r) {
            res.push_back({l, r});
            ++l; --r;
        }
    }
    else {
        res.push_back({k, n-1});
        int l = 1, r = n-2;

        while(l<r) {
            if(l == k) res.push_back({0, r});
            else if(r == k) res.push_back({0, l});
            else res.push_back({l, r});
            ++l; --r;
        }
    }

    if(res.size() != (n/2)) cout << -1 << "\n";
    else
        for(auto& i : res) 
            cout << i.first << " " << i.second << "\n";



}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}