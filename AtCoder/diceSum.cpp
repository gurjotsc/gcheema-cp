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
    const int MOD = 998244353;
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> dp(N+1, vector<int>(K+1)); //dp[i][j] = how many ways to get j using i dice
    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j) 
            for(int k = 0; k <= K; ++k) {
                if(k+j > K) continue;
                int x = dp[i-1][k]; //ways to get k from i-1 dice
                dp[i][k+j] += x; //using out current dice with value j, take all the number of ways to get k and then add our current dice to it. This gives you how many ways we should add to dp[i][k+j]
                dp[i][k+j] %= MOD;
            }
    
    int res = 0;
    for(int i = 0; i <= K; ++i) res = (res+dp[N][i])%MOD;

    return res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cout << solve();
}