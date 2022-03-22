#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

string solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    ll w = 0ll;
    for(auto& i : a) {
        cin >> i;
        w += i;
    }
    if(n == 1) return "YES";

    multiset<ll> sim = {w};
    multiset<ll> orig(a.begin(), a.end());

    while(!sim.empty()) {
        auto curr = *--sim.end(); //largest slice in simulation cake (-- because .end() points after the last element)
        if(curr < *--orig.end()) return "NO"; //If the current slice is less than the biggest in orig, then we can never get back to that bigger size since curr can only get smaller from here. hence it is not possible
        
        sim.erase(--sim.end()); //erase this from the sim
        if(orig.count(curr)) orig.erase(--orig.end()); //if this slice occurs in the orig, then remove it and move on. We will continue simulation on the remainder of the sim cake since this slice is now "complete and untouchable/unchangeable in our simulation"
        else {
            //else we cut the slice
            if((curr/2) * 2 == curr) {
                sim.insert(curr/2);
                sim.insert(curr/2);
            }
            else {
                sim.insert(curr/2);
                sim.insert((curr/2)+1);
            }
        }
    }

    if(orig.empty()) return "YES"; //our simulation has covered all the slices in orig (and maybe even more possible slices)

    return "NO"; //There is some remaining uncovered slice



}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}