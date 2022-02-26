#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        ll n, x; cin >> n >> x;
        ll res = 0ll;
        vector<ll> a(n);
        unordered_map<ll, int> freq;
        for(auto& i : a) {
            cin >> i;
            if(freq.find(i) == freq.end()) freq[i] = 1;
            else ++freq[i];
        }
        // 17 2
        // 4 2 1 8 17 17 5 5 12 2 16 17 9 7 12 2 15
        // 1 1
        // 2 3
        // 4 1
        // 5 2
        // 7 1
        // 8 1
        // 9 1
        // 12 2
        // 15 1
        // 16 1
        // 17 3
        //print 11 should be 13
        for(auto& i : a) {
            if(!freq[i]) continue;
            if(freq.find(i*x) != freq.end() && freq[i*x] > 0) {
                --freq[i];
                --freq[i*x];
            }
        }

        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if(!it->second) continue;
            else res += it->second;
        }

        cout << res << endl;


    }
}

