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
    int n, a, b; cin >> n >> a >> b;
    vector<int> x(n+1); x[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> x[i];
        

    int res = 0;
    bool conqueringStage = false;
    bool movingStage = true;
    int lockedCapitalIdx = 0;
    for(int i = 1; i <= n; ++i) {
        int remaining = n-i+1; //plus 1 cuz its one indexed
        int distance = x[i] - x[i-1];
        if(b*distance*remaining < distance*(a+b)) {
            conqueringStage = true;
            movingStage = false;
        }


        //you should always just conquer shit unless its not costworthy to do so
        //in that case just conquer the next kingdom and move there (a+b)
        //at the beginning you always move the capital. The point at which you start conquring, you always conquer because you can no longer move

        if(movingStage) {
            distance = x[i] - x[i-1];
            res += (distance*(a+b));
            lockedCapitalIdx = i;
        }
        if(conqueringStage) {
            distance = x[i] - x[lockedCapitalIdx];
            res += (b*distance);
        }
    }

    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) cout << solve() << "\n";
}
