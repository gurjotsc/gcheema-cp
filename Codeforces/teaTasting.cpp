#include <algorithm>
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
 
vector<ll> solve() {
    ll n; cin >> n;
	vector<ll> a(n), b(n); cin >> a >> b;
	vector<ll> cnt(n+1), add(n+1), res(n);
	vector<ll> psum(n+1);
	for(int i = 0; i < n; ++i) psum[i+1] = psum[i]+b[i];
 
	for(int i = 0; i < n; ++i) {
		int j = upper_bound(begin(psum), end(psum), a[i]+psum[i])-begin(psum)-1;
		++cnt[i]; --cnt[j];
		add[j] += a[i]-(psum[j]-psum[i]);
	}
 
	for(int i = 0; i < n; ++i) {
		cnt[i] += (i) ? cnt[i-1] : 0;
		res[i] = (cnt[i]*b[i])+add[i];
	}
	return res;
}
 
 
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}