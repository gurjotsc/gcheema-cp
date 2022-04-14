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


int res = 0;

void inject(vector<int>& a) {
    int n = a.size();
    if(!n) return;
    int lastMax = -1;
    for(int i = 0; i < n; ++i) {
        if(a[i] == a[0]) lastMax = i;
        else break;
    }
    --a[lastMax]; //inject the max
    for(int i = 0; i < n; ++i) --a[i]; //everything spreads
    sort(all(a), [&](int a, int b) {return a > b;}); //resort
    while(!a.empty() && a.back() <= 0) a.pop_back(); //pop any zeroes
    ++res;
    inject(a);
}

ll solve() {
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 2; i <= n; ++i) {
        int p; cin >> p;
        ++a[--p];
    }
    a.push_back(1); //root
    
    sort(all(a), [&](int a, int b) {return a > b;});
    while(!a.empty() && a.back() <= 0) a.pop_back();
    
    for(int i = 0; i < a.size(); ++i) {
        a[i] -= (a.size()-i);
        ++res;
    }
    
    sort(all(a), [&](int a, int b) {return a > b;});
    while(!a.empty() && a.back() <= 0) a.pop_back();
    
    inject(a);

    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        cout << solve() << "\n";
        res = 0;
    }
}