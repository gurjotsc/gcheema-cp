#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using schlong = long;
using ull = unsigned long long;
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


schlong res, n;
vector<schlong> order;

void recurse(schlong curr = n, schlong cnt = 0, schlong prev = -1) {
    if(cnt > 40 || curr < 1 || res != -1)
        return;
    if(curr == 1) {
        res = cnt;
        order.push_back(prev);
        return;
    }
    schlong x1 = (curr+1)/2;
    schlong x2 = (curr-1)/2;

    recurse(x1, cnt+1, 1);
    recurse(x1, cnt+1, 2);
}

void solve() {
    schlong n; cin >> n;
    if(!(n%2)) {
        cout << "-1";
        return;
    }

    vector<schlong> res;
    schlong f = 0;
    for(int i = 29; i >= 1; --i) {
        if((n >> i) & 1) {
            f = 1;
            res.push_back(2);
        }
        else if (f)
            res.push_back(1);
    }

    cout << res.size() << "\n" << res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}
