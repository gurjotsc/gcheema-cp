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


string solve() {
    int n, m; cin >> n >> m;
    vector<array<ll, 3>> items(n+m);
    multiset<ll> s;
    
    for(int i = 0; i < n; ++i) {
        cin >> items[i][0]; //width
        items[i][2] = 0ll;
    }
    for(int i = 0; i < n; ++i) {
        cin >> items[i][1]; //length
        items[i][2] = 0ll;
    }
    for(int i = n; i < n+m; ++i) {
        cin >> items[i][0]; //width
        items[i][2] = 1;
    }
    for(int i = n; i < n+m; ++i) {
        cin >> items[i][1]; //length
        items[i][2] = 1;
    }

    if(n > m) return "No";

    sort(items.begin(), items.end(), 
    [&](array<ll, 3> a, array<ll, 3> b) 
    {
        if(a[0] == b[0]) return a[2] < b[2];
        return a[0] < b[0];
    }
    );

    for(int i = items.size()-1; i >= 0; --i) {
        if(items[i][2] == 1) s.insert(items[i][1]);
        else {
            auto it = s.lower_bound(items[i][1]);
            if(it == s.end()) return "No";
            else s.erase(it);
        }
    }
    return "Yes";
    
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cout << solve();
}