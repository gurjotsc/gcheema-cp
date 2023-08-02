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


string solve() {
    string s; cin >> s;
    int n = s.size();
    if(n == 1) {
        if(s[0] == '?') return "a";
        else return s;
    }
    for(int i = 0; i < n; ++i) {
        if(s[i] != '?') {
            if(i < n-1)
                if(s[i+1] == s[i]) return "-1";
            continue;
        }

        int l = i, r = i;
        while(r < n && s[r] == '?')
            ++r;
        if(r == n) {
            int cnt = (s[l-1] == 'a') ? 1 : 0;
            while(l < n) {
                s[l++] = 'a'+(cnt%2);
                ++cnt;
            }
        }
        else {
            vector<char> arr;
            if(s[r] == s[l-1]) {
                for(auto& c : {'a', 'b', 'c'})
                    if(c != s[r])
                        arr.push_back(c);
            }
            else {
                for(auto& c : {'a', 'b', 'c'})
                    if(c != s[r] && c != s[l-1])
                        arr.push_back(c);
                arr.push_back(s[l-1]);
            }
            
            int cnt = 0;
            while(l < r) {
                s[l++] = arr[cnt%2];
                ++cnt;
            }
        }
        i = l-1;
    }
    return s;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}