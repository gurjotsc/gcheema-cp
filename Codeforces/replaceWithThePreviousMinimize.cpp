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


string solve() {
    ll n,k; cin >> n >> k;
    string s; cin >> s;
    //you can reduce anything that 25 or more operations to 'a' since 'z'->'a' is 25 operations
    //zzzzz->aaaaa only takes 25 operations
    if(k >= 25) {
        for (auto& c : s) c = 'a';
        return s;
    }
    //find the maxVaildChar that comes before the first point at which you can't reduce a character completley to a
    //this is the point where reducing things after becomes obsolete to reducing those that come before (Since the ones before have higher placeholders)
    //subtract k with how many operations it will cost to get mxValidChar down to 'a'. This is how many operations you have to spare
    //That means that you can go from c (since we itereate l to r this is the first unvalid character with the highest placeholder) to  k - mxVaildChar - 'a' since thats how many operations you can spare
    //Simulate this for all character in the "spare" k range (which is "stop" here)
    char mxVaildChar = 'a';
    for (auto c : s) if(c > mxVaildChar) {
        if (c - 'a' > k) { 
            k -= mxVaildChar - 'a';
            int stop = c - k;

            for (auto x = c; x > stop; x--)
                for (auto& e : s) 
                    if (e == x) e = char(x-1); //simulate

            break;
        } else mxVaildChar = max(mxVaildChar, c);
    }
    //reduce what end up less than mxVaildChar to 'a'
    for (auto& c:s) 
        if (c <= mxVaildChar) c = 'a';
    return s;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}