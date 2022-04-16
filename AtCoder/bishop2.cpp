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
    int ax, ay; cin >> ax >> ay;
    int bx, by; cin >> sx >> sy;
    ax--; ay--; sx--; sy--;
    vector<string> board(n);
    cin >> board;

    if(ax == sx && ay == sy) return 0;
    queue<array<int, 4>> q;
    vector<array<int, 2>> dirs = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}}; //Bottom right, bottom left, up right, up left
    q.push({ax, ay, 0, -1});
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto curr = q.front(); q.pop();
            if(curr[0] == sx && curr[1] == sy) return curr[2];
            for(int i = 0; i < 4; ++i) {
                int x = curr[0] + dirs[i][0];
                int y = curr[1] + dirs[i][1];

                if(board[x][y] == '#') continue;
                if(x < 0 || x > board.size()-1) continue;
                if(y < 0 || y > board[0].size()-1) continue;

                if(curr[3] == i) q.push({x, y, curr[2], i});
                else q.push({x, y, curr[2]+1, i});
            }
        }
    }
    return -1;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cout << solve() << "\n";
}