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


ll solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n); cin >> a >> b;
    map<ll, ll> m; 
    vector<pll> v(n);

    for(ll i = 0; i < n; ++i) {
        m[a[i]] = i;
        v[i] = {b[i], i};
    }
    sort(all(v));

    //currMinSwap is going to store the value of a bigger numbers swap and replace v[i].second ONLY IF there is a bigger number that can be moved to the front in less swaps thus making b lexicographically larger and swapping b[i] obsolete (as opposed to the less constly larger number in currMinSwaps)
    //suffix array
    //store the best until there is smth potentially better
    //iterate backwards
    //i.e   
    //b = 5 4 9 11 7 10 1
    //v = {1, 6} {4, 1} {5, 0} {7, 4} {9,2} {10, 5}  {11, 3}
    //currMinSwap for each
    ////v = {1, 0} {4, 0} {5, 0} {7, 2} {9,2} {10, 3}  {11, 3} //now we store the quickest and best way to make b lexicographically larger using that number (or not if currMinSwaps has found a less costly one)
    ll currMinSwap = LLONG_MAX;
    for(ll i = n-1; i >= 0; --i) {
        currMinSwap = min(currMinSwap, v[i].second);
        v[i].second = currMinSwap;
    }
    //since a stores all odds and b stores all evens, i is always < v[j].first; (i.e, when j = 0, v[j].first = 2)
    //lets assume we move i to the front, how many swaps will that take?
    //well we know that v[j].first is the next number that would make b lexicographically larger than a
    //so how many swaps will that take to move v[j].first (remember that v[j].second could store a bigger number that could move quicker since it would still work in making b lexicographically larger than a for this i)
    //add the two together
    //store the minimum
    ll res = LLONG_MAX;
    ll j = 0;
    for(int i = 1; i <= 2*n; i += 2) 
        res = min(res, m[i]+v[j++].second);
    
    return res;

}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}