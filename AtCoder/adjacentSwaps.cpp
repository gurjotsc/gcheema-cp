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


void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> x(q); cin >> x;
    vector<ll> a(n+1);
    map<ll, ll> m; //num to idx
    for(int i = 1; i <= n; ++i) {
        a[i] = i;
        m[i] = i;
    }

    for(auto xi : x) {
        ll idx = m[xi];
        if(idx+1 <= n) {
            m[a[idx]] = idx+1;
            m[a[idx+1]] = idx;
            swap(a[idx], a[idx+1]);
        }
        else {
            m[a[idx]] = idx-1;
            m[a[idx-1]] = idx;
            swap(a[idx], a[idx-1]);
        }
    }
    
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
}