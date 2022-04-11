#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data) {
     for (auto& item : data) input >> item;
     return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data) {
     for (const T& x : data) output << x << " " ;
     return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::pair<T, T>& data) {
    output << "{" << data.first << ", " << data.second << "}";
    return output;
}
template <typename T, typename U>
std::ostream& operator <<(std::ostream& output, const std::map<T, U>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << "{" << it->first << ", " << it->second << "} ";
    return output;
}
template <typename T, typename U>
std::ostream& operator <<(std::ostream& output, const std::unordered_map<T, U>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << "{" << it->first << ", " << it->second << "} ";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::set<T>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << *it << " ";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::unordered_set<T>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << *it << " ";
    return output;
}
ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

struct Tarjan {
    int N;
    int T = 0, C = 0;
    vector<int> path;
    vector<bool> curr;
    vector<int> disc, low, scc;
    vector<vector<int>> &adj;

    void dfs(int u) {
        curr[u] = true;
        int i = path.size();
        path.push_back(u);
        disc[u] = low[u] = T++;
        for (int v : adj[u]) {
            if (disc[v] == -1) {  // if not visited
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (curr[v])  // genius part
                low[u] = min(low[u], disc[v]);
        }
        if (low[u] == disc[u]) {  // found an SCC
            int id = C++;
            for (int j = i; j < path.size(); ++j) {
                scc[path[j]] = id;
                curr[path[j]] = false;
            }
            path.resize(i);
        }
    }

    inline int operator[](int i) { return scc[i]; }

    Tarjan( vector<vector<int>> &g )
        : N(g.size()), adj(g), scc(N), low(N,-1), disc(N,-1), curr(N) {
        for (int i = 0; i < N; ++i)  // adjust me maybe
            if (disc[i] == -1)
                dfs(i);
    }
};

int res = 0;
int dfs(int i, Tarjan& t, vector<int>& dp, vector<int>& cnt) {
    if(cnt[t[i]] >= 2) return 1;
    if(dp[i] != -1) return dp[i];
    for(int j : t.adj[i])
        if(dfs(j, t, dp, cnt)) return dp[i] = 1;
    return dp[i] = 0;
}

int solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    Tarjan t(adj);
    int c = t.C;
    vector<int> cnt(c);
    vector<int> dp(n,-1);
    for(int i = 0; i < n; ++i) ++cnt[t[i]];
    for(int i = 0; i < n; ++i) res += dfs(i, t, dp, cnt);

    return res;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve();
    // int t; cin >> t;
    // while (t--) cout << solve() << "\n";
}