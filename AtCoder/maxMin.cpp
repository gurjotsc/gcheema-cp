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


ll solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n+1); 
    ll res = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int lastX = -1, lastY = -1;
    int l = 1;
    for(int r = 1; r <= n; ++r) {
        if(a[r] == x) lastX = r;
        if(a[r] == y) lastY = r;
        if(a[r] > x || a[r] < y) {
            lastX = lastY = -1;
            l = r+1;
        }
        if(lastX != -1 && lastY != -1) res += min(lastX, lastY) - l+1;
    }

    return res;
    
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve();
    // int t; cin >> t;
    // while (t--) cout << solve() << "\n";
}