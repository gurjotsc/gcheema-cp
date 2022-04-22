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

bool colinear(pll i, pll j, pll x) {
    ll value1 = (j.first-i.first)*(x.second-i.second);
    ll value2 = (j.second-i.second)*(x.first-i.first);
    return value1 == value2;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<pll> c(n); 
    vector<vector<bool>> seen(n, vector<bool>(n)); //true means you done the line through this pair
    ll res = 0;
    for(auto& i : c) cin >> i.first >> i.second;
    if(k == 1) {
        cout << "Infinity";
        return;
    }

    for(ll i = 0; i < n; ++i)
        for(ll j = i+1; j < n; ++j) {
            if(seen[i][j]) continue;
            vector<ll> vc; //vc = validCoordinates
            ll cnt = 2;
            vc.push_back(i); vc.push_back(j);
            for(ll x = j+1; x < n; ++x) { //iterate starting from x = j+1, because lets say you didn't do this (so you start from x = 0) then if i = 0, x = 1, and j = 2, you get the same thing as i=0, j=1, and x=2 which already happened in a previous iteration
                if(colinear(c[i], c[j], c[x])) {
                    ++cnt;
                    vc.push_back(x);
                }
                for(ll ii = 0; ii < vc.size(); ++ii)
                    for(ll jj = ii + 1; jj < vc.size(); ++jj) 
                        seen[vc[ii]][vc[jj]] = true; //you have seen this pair
            }
            if(cnt >= k) res++;
        }
            
    cout << res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
}