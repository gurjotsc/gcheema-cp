#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

int querey(int i) {
    cout << "? " << i+1 << endl;
    int res; cin >> res;
    return res-1;
}

vector<int> solve() {
    int n; cin >> n;
    vector<int> res(n,-1);

    for(int i = 0; i < n; ++i) {
        if(res[i] != -1) continue;
        //we always querey idx zero until we find a cycle, once we do we add everything to res
        //iterate through res and see if there is any unfilled idxs
        //start searching for a cycle there
        //if you find a repeat thats already filled in res, the "cycle" vector should always output the same thing for an index
        vector<int> cycle;
        int cycleStart = querey(i);
        int curr = querey(i);
        cycle.push_back(curr);
        while(curr != cycleStart) {
            curr = querey(i);
            cycle.push_back(curr);
        }
        for(int j = 0; j < cycle.size(); ++j) 
            res[cycle[j]] = cycle[(j+1)%cycle.size()];
    }

    return res;

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        vector<int> p = solve();
        cout << "! ";
        for(auto& i : p) cout << i+1 << " ";
        cout << endl;
    }
}