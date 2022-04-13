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

int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
ll solve() {
    int H, W, N; cin >> H >> W >> N;
    int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
    map<int, vector<int>> Xs, Ys;
    for(int i = 0; i < N; ++i) {
        int X, Y; cin >> X >> Y;
        Xs[Y].push_back(X);
        Ys[X].push_back(Y);
    }

    for(auto& [v,l] : Xs) sort(all(l));
    for(auto& [v,l] : Ys) sort(all(l));

    queue<pll> q; q.push({sx, sy});
    set<pll> seen;
    int depth = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [startX, startY] = q.front(); q.pop();
            if(startX == gx && startY == gy) return depth;
            auto right = lower_bound(all(Xs[startY]), startX);
            auto down = lower_bound(all(Ys[startX]), startY);
            auto left = prev(right);
            auto up = prev(down);

            if(right != Xs[startY].end() && !seen.count({*right-1, startY})) {
                q.push({*right-1, startY});
                seen.insert({{*right-1, startY}});
            }
            if(down != Ys[startX].end() && !seen.count({startX, *down-1})) {
                q.push({startX, *down-1});
                seen.insert({startX, *down-1});
            }
            if(right != Xs[startY].begin() && !seen.count({*left+1, startY})) {
                q.push({*left+1, startY});
                seen.insert({*left+1, startY});
            }
            if(down != Ys[startX].begin() && !seen.count({startX, *up+1})) {
                q.push({startX, *up+1});
                seen.insert({startX, *up+1});
            }
        }
        depth++;
    }

    return -1;


}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve();
    // int t; cin >> t;
    // while (t--) cout << solve() << "\n";
}