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

vector<vector<ll>> factors(1e5);


ll solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n); cin >> a;
    sort(begin(a), end(a));
    vector<ll> freq(m+1);
    ll cnt = 0; //counts the number of unique numbers from 1...m which are multiples of the numbers represented by the iteration we're on. 
    ll l = 0;
    ll res = inf;
    for(int r = 0; r < n; ++r) { //iterate over the array
        for(auto& x : factors[a[r]]) { //were adding a[r] to our current solution so we need to account for all its factors
            if(x > m) break;
            cnt += (!freq[x]); //some factor from 1...m gets accounted for
            ++freq[x];
        }
        while(cnt == m) { //while the solution is still valid
            ll curr = a[r] - a[l];
            res = min(res, curr); //update the solution (a[l] will always be the smallest number in our solution and a[r] will always be the largest) since a is sorted)
            for(auto& x : factors[a[l]]) { //were removing a[l] from our current solution so we need to account for all its factors and decrement freq and cnt accordingly
                if(x > m) break;
                --freq[x];
                cnt -= (!freq[x]);
            }
            ++l; //move the left pointer to the right
        }
    }
    return (res != inf) ? res : -1;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    for(int i = 1; i<= 1e5; ++i)
        for(int j = i; j <= 1e5; j += i) factors[j].push_back(i);

    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}