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


string solve() {
    schlong n; cin >> n;
    vector<schlong> queries(n); cin >> queries;
    vector<schlong> a;
    string res = "";
    schlong mn;
    bool move = false;
    for(auto& q : queries) {
        if(!a.size()) {
            a.push_back(q);
            res += "1";
        }
        else {
            if(move) {
                if(q >= mn && q <= a.front()) {
                    mn = q;
                    a.push_back(q);
                    res += "1";
                }
                else res += "0";
            }
            else {
                if(q >= a.back()) {
                    a.push_back(q);
                    res += "1";
                }
                else if(q <= a.front()) {
                    mn = q;
                    move = true;
                    a.push_back(q);
                    res += "1";
                }
                else res += "0";
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