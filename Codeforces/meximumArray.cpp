#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    map<int, int> freq;
    set<int> unique;
    for(auto& i : a) {
        cin >> i;
        ++freq[i];
    }

    int mex = 0; //max mex seen so far in the next for loop
    for(int i = 0; i < n; ++i) {
		--freq[a[i]];
        unique.insert(a[i]);
		//calculate mex so far for this subarray
        while(unique.count(mex)) ++mex;
		//if there is a value farther down the range for mex
		//then this won't run
		//if the next largest value is bigger than mex, 
		//then your mex including that value is still gonna be the same 
		//so theres no point in waiting for that integer to appear in the loop
        if(!freq[mex]) { //if this is not true, we can expect the mex in the future so we could get a higher mex down the range
            unique.clear(); //restart with a new subarray
            b.push_back(mex);
            mex = 0;
        }
    }
    cout << b.size();
	if(b.size()) cout << "\n";
    for(auto& i : b) cout << i << " ";

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