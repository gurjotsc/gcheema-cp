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


int solve() {
    int n;
    string s;
    cin >> n >> s;

    char a, b;
    int i = 0, j = n-1;
    while(i <= j) {
        if(s[i] != s[j]) {
            a = s[i], b = s[j];
            break;
        }
        ++i;
        --j;
    }

    int res = INT_MAX;
    for(auto c : {a, b}) {
        int i = 0, j = n-1;
        bool flag = false;
        int ans = 0;
        while(i <= j) {
            if(i == j) {
                ++i;
                --j;
                continue;
            }

            if(s[i] == s[j]) {
                ++i;
                --j;
            }
            else {
                if(s[i] == c) {
                    ++i;
                    ++ans;
                }
                else if (s[j] == c) {
                    --j;
                    ++ans;
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) res = min(res, ans);
    }
    return (res == INT_MAX) ? -1 : res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}