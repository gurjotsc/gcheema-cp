#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> factorials;
map<ll, int> fSumSubsets;

int solve() {
    ll n; cin >> n;
    int k = INT_MAX;
    ll maxBits = log2(n)+1;
    int cnt = 0;
    for(int i = 0; i <= maxBits; ++i) 
        if(n & (1 << i)) ++cnt;
    k = cnt;
    for(auto it = fSumSubsets.begin(); it != fSumSubsets.end(); ++it) {
        ll curr = n - it->first;
        if(curr < 0) break;

        maxBits = log2(curr)+1;
        cnt = 0;
        for(int i = 0; i <= maxBits; ++i) 
            if(curr & (1 << i)) ++cnt;
        k = min(k, cnt + it->second);
    }

    return k;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    ll f = 1;
    ll prev = f;
    ll check = 10e12;
    factorials.push_back(f);
    while((prev*f) <= check) {
        factorials.push_back(f*prev);
        prev = f*prev;
        ++f;
    }
    for(int i = 0; i < pow(2,factorials.size()); ++i) {
        ll sum = 0;
        int cnt = 0;
        int j = 0;
        while(j < factorials.size()) {
            if(i & (1<<j)) {
                sum += factorials[j];
                ++cnt;
            }
        }
        if(!fSumSubsets.count(sum)) fSumSubsets[sum] = cnt;
        else fSumSubsets[sum] = min(fSumSubsets[sum], cnt);
    }

    while(t--) cout << solve() << "\n";
}