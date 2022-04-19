#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define int ll
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> res(n);
    int x = k;
    //not including last bit
    for(int i = 0; i < n-1; ++i) {
        //if you have no moves left OR (if its 0, then with k moves it won't change and selecting it to stay the same it won't help OR if its 1 then you should just pass since its the best it ca be) (the second part is all 1 case)
        if(!x || ((s[i]) - '0' + k)%2) continue;
        else {
            res[i] = 1;
            --x;
        }
    }
    res[n-1] = x; //Remaining number of moves
    for(int i = 0; i < n; ++i) 
        //if after selecting this ans[i] times, will the other moves change the value
        //if so then change it
        if((k-res[i])%2) s[i] = (s[i] == '0') ? '1' : '0';

    cout << s << "\n" << res << "\n";
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) solve();
}