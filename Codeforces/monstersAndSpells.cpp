#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll sum(ll i) {
	return (((i)*(i+1))/2);
}

ll solve() {
    int n; cin >> n;
    vector<ll> k(n);
    vector<ll> h(n);
    ll mana = 0ll;
    for(auto& i : k) cin >> i;
    for(auto& i : h) cin >> i;

    for(int i = 0; i < n; ++i) {
        if(!i) {
			mana += sum(h[i]);
            continue;
            // mana.push_back(h[i]);
        }
        else if(k[i] - k[i-1] >= h[i]) mana += sum(h[i]);
        else {
			diff = k[i]-k[i-1];
			mana += ((mana*diff) + (sum[diff]);
		}
        // if(k[i] - k[i-1] >= h[i]) mana.push_back(h[i]);
        // else mana[mana.size()-1] += (k[i] - k[i-1]);
    }

    return mana;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}

// 3
// 1
// 6
// 4
// 2
// 4 5
// 2 2
// 3
// 5 7 9
// 2 1 2