#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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


vector<ll> solve() {
    ll n; cin >> n;
    vector<ll> c(n); cin >> c;
    vector<ll> a(n), b(n);
    a[n-1] = (c[n-1] == n); //if c[n-1] is n then 1 is at the end in all the binary strings
                            //if cn[n-1] is exactly 1 and n != 1, then that just means there is a 1 somewhere and it got sorted to the end in Bn (i.e, a = 0001000, then Bn = 0000001)
    ll sum = accumulate(all(c), 0); //each 1 will appear in each of the binary strings regardless of if its sorted. This means that taking the sum and dividing by n will give you numOnes
    ll numOnes = sum/n;
    ll start = n-numOnes-1;
    for(ll i = start; i < n; ++i) b[i] = n-1;
    for(ll i = n-1; i >= 0 && i >= start; --i) {
        ll remaining = b[i]-i; //remaining to the right
        ll curr = c[i] - remaining; //how many times a 1 apparead - how many are to the right of it
        if(curr == i+1) a[i] = 1;
        else if(curr == 1) {
            a[i] = 0; //already 0 so not needed
            b[--start] = i-1;
        }
    }

    return a;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}