#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll sum(ll i) {return (((i)*(i+1))/2);}

ll solve() {
    int n; cin >> n;
    vector<ll> k(n);
    vector<ll> h(n);
    vector<vector<ll>> mana;
    vector<vector<ll>> merge;
	ll res = 0ll;
    for(auto& i : k) cin >> i;
    for(auto& i : h) cin >> i;

    //stores when you need to start chargin up until your cast (k[i])
    for(int i = 0; i < n; ++i) {
		if(h[i] == 1) ++res;
		else mana.push_back({k[i]-h[i], k[i]});
	}
    //sorts by mana[0] aka what needs to start charging up first
	sort(mana.begin(), mana.end());
    for(auto i : mana) cout << i[0] << " " << i[1] << "/";
	cout << "\n";
    for(int i = 0; i < mana.size(); ++i) {
		if(!merge.size()) merge.push_back(mana[i]);
        else if(mana[i][0] > merge[merge.size()-1][1]) merge.push_back(mana[i]);
        else {
			merge[merge.size()-1][1] = max(merge[merge.size()-1][1], mana[i][1]);
			//if(mana[i-1][0] == mana[i-1][1]-1) ++merge[merge.size()-1][0];
		}
    }

	for(auto i : merge) cout << i[0] << " " << i[1] << "/";
	cout << "\n";
	for(auto i : merge) res += sum(i[1] - i[0]);

    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}