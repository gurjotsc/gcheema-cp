#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define all(x) begin(x), end(x)

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

ll res;

void dfs(vector<vector<ll>>& graph, vector<ll>& numNodes, vector<ll>& dp, ll root, ll parent) {
    if(!root) return;
    numNodes[root] = 1;
    dp[root] = 0; 
    ll l = 0, r = 0; //the two children of a root
    for(auto& i : graph[root]) 
        if(i != parent) { //because we push_back the parent along with the kids
            if(!l) l = i;
            else r = i;
        }
    dfs(graph, numNodes, dp, l, root);
    dfs(graph, numNodes, dp, r, root);
    numNodes[root] += (numNodes[l]+numNodes[r]); //get total nodes in subtree
    //lets assume we save the right (same logic for left)
    //then (dp[l]+numNode[r]-1) = 
    //(how many we can save assming l gets infected)+(the number of nodes we save on the right) - (1 node since we need to delete r to save the remainder of the subtree)
    dp[root] = max(dp[l]+numNodes[r]-1, dp[r]+numNodes[l]-1);
    dp[root] = max(dp[root], 0ll); //in the case of a leaf node (dp[l/r]+numNodes[r/l]-1 = 0+0-1 == -1)
}

ll solve() {
    ll n; cin >> n;
    vector<vector<ll>> graph(n+1);
    vector<ll> numNodes(n+1, 0); //stores total nodes of subtree at vertex root
    vector<ll> dp(n+1, 0); //store the answer for a subtree at root i assuming i is the infected root (aka max number of nodes you can save assuming i is the infected root)
    res = 0;
    //all nodes only have two children (says in question)
    for(int i = 0; i < n-1; ++i) {
        ll u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(graph, numNodes, dp, 1, 0);
    res = dp[1];
    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}