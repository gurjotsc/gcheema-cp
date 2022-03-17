#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

void dfs(vector<vector<vector<int>>>& g, vector<int>& res, int v, int parent, int w) {
    for(auto& x : g[v]) {
        int u = x[0], i = x[1];
        if(u != parent) {
            res[i] = w;
            if(w == 2) dfs(g, res, u, v, 3);
            else dfs(g, res, u, v, 2);
        }
    }
}
void solve() {
    int n; cin >> n;
    vector<vector<vector<int>>> g(n);
    vector<int> deg(n);
    vector<int>  res(n-1);
    int minIdx;
    for(int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        ++deg[u]; ++deg[v];
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    minIdx = 0;
    for(int i = 0; i < n; ++i) {
		if(deg[i] >= 3) {
            cout << -1;
            return;
        }
        if(deg[i] < deg[minIdx]) minIdx = i;
	}

    dfs(g, res, minIdx, -1, 2);

    for(auto& i : res) cout << i << " ";


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

