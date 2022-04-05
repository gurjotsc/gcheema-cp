#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define int ll

template<typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
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
    for(auto it = data.begin(); it != data.end(); ++it) output << it->first << " ";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::unordered_set<T>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << it->first << " ";
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

const ll MOD = 998244353;

int solve() {
    ll n, l; cin >> n >> l;
    vector<string> s(n); cin >> s;
    ll res = 0;

    ll numSubsets = pow(2, n);
    
    for(int i = 1; i < numSubsets; ++i) {
        vector<int> repeats(26);
        int charactersInIntersection = 0;
        
        for(int j = 0; j < n; ++j)
            if(i & (1 << j))
                for(char& c : s[j]) repeats[c-'a']++;
        
        int subsetSize = __builtin_popcountll(i);
        for(auto& f : repeats) charactersInIntersection += (f == subsetSize);

        int intersectionStrings = modPow(charactersInIntersection, l, MOD);
        int parity = (subsetSize%2) ? 1 : -1; //odd subsets we count, but even ones we don't. Even counts will have appeared before and represent an intersection
        res = (((res+(intersectionStrings * parity))%MOD)+MOD)%MOD;
    }
    
    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cout << solve();
}
