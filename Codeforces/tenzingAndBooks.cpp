#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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


void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(n), c(n); cin >> a >> b >> c;
    int largest_set_bit = 31-__builtin_clz(x);
    unordered_set<int> s;
    for(int i = 0; i <= largest_set_bit; ++i)
        if(x & (1 << i))
            s.insert(i);
    
    int i, j, k;
    auto check = [&](int test) -> bool {
        int test_largest_set_bit = 31-__builtin_clz(test);
        for(int ii = 0; ii <= test_largest_set_bit; ++ii)
            if(test & (1 << ii)) {
                if(!s.count(ii))
                    return false;
            }
        return true;
    };

    for(i = 0; i < n; ++i) {
        if(!check(a[i]))
            break;
    }
    for(j = 0; j < n; ++j) {
        if(!check(b[j]))
            break;
    }
    for(k = 0; k < n; ++k) {
        if(!check(c[k]))
            break;
    }

    int res = 0;

    for(int ii = 0; ii < i; ++ii) 
        res |= a[ii];
    for(int jj = 0; jj < j; ++jj) 
        res |= b[jj];
    for(int kk = 0; kk < k; ++kk) 
        res |= c[kk];
    
    
    cout << ((res == x) ? "yEs" : "nO") << "\n";
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) 
        solve();
}