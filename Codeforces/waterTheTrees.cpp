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


ll solve() {
    int n; cin >> n;
    vector<ll> h(n);
    cin >> h;
    ll mx = *max_element(all(h));
    ll res = LLONG_MAX;
    for(auto need : {mx, mx+1}) {
        ll lo = 0; 
        ll hi = 1e18;
        ll currRes = -1;
         while(lo < hi) {
            ll mid = lo+((hi-lo)/2);
            ll cnt1 = ((mid+1)/2), cnt2 = mid/2; //ceil cnt1 cuz we start on day one which is odd
            ll need1 = 0; //how many times you actually need to add 1. cnt1 and cnt2 is the max possible 1s and 2s you could add
            for(auto i : h) {
                ll curr = (need-i)/2; //Try to add only 2s to this one
                if((need-i)%2) ++need1; //you would need to add one to this since it is a different parity than the need
                if(cnt2 >= curr) cnt2 -= curr; //always choose 2 greedily since its 
                else {
                    curr -= cnt2;
                    cnt2 = 0;
                    need1 += (curr*2); //you need to add ones since you are out of 2 days
                }
            }
            if(need1 <= cnt1) { //note this might work but it won't makes sense ie you need to use odd even odd even, 
                                //but this solution uses all even first (see the last if else in the for loop through h)
                                //so binary search will find the min possible solution 
                                //(aka the solution where odd even does work since need1 and cnt2 will only be off by 1)
                currRes = mid;
                hi = mid;
            }
            else lo = mid+1;    
        }
        res = min(res, currRes);
    }
    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}