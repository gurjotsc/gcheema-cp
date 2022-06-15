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


string solve() {
    ll n, m, k; cin >> n >> m >> k;
    string x, y; cin >> x >> y;
    multiset<char> a(all(x)), b(all(y));
    ll aUsed = 0, bUsed = 0;
    string res = "";
    while(a.size() && b.size()) {
        if(*a.begin() < *b.begin() && aUsed < k) {
            res += *a.begin();
            a.erase(a.begin());
            aUsed++;
            bUsed = 0;
        }
        else if (*b.begin() < *a.begin()) {
            if(bUsed < k) {
                res += *b.begin();
                b.erase(b.begin());
                bUsed++;
                aUsed = 0;
            }
            else {
                res += *a.begin();
                a.erase(a.begin());
                aUsed++;
                bUsed = 0;
            }
        }
        else { //equal, then choose the one with less elements
            if(a.size() < b.size() && aUsed < k) {
                res += *a.begin();
                a.erase(a.begin());
                aUsed++;
                bUsed = 0;
            }
            else {
                if(bUsed < k) {
                    res += *b.begin();
                    b.erase(b.begin());
                    bUsed++;
                    aUsed = 0;
                }
                else {
                    res += *a.begin();
                    a.erase(a.begin());
                    aUsed++;
                    bUsed = 0;
                }
            }
        }
    }
    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}