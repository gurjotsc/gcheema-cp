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

ll numKids(vector<vector<ll>>& g, vector<ll>& k, ll i) {
    if(!g[i].size()) return 0;
    for(auto& x : g[i]) k[i] += (1+numKids(g, k, x));
    return k[i];
}

void recurse(vector<vector<ll>>& g, vector<ll>& k, ll i) {
    //delete node with more children (node not counted)
    //call recurse on the OTHER infected neighbors children
    //repeat until leaf or no neighbor
    if(!g[i].size()) return;
    else if(g[i].size() == 1) res += k[g[i][0]];
    else {
        ll k1 = g[i][0], k2 = g[i][1];
        if(k[k1] > k[k2]) {
            res += k[k1];
            recurse(g, k, k2);
        }
        else {
            res += k[k2];
            recurse(g, k, k1);
        }
    }
}

ll solve() {
    ll n; cin >> n;
    vector<vector<ll>> g(n+1);
    vector<ll> k(n+1, 0);
    res = 0;
    for(int i = 0; i < n-1; ++i) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    
    ll dummy = numKids(g, k, 1);
    recurse(g, k, 1);
    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}