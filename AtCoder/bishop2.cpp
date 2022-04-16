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

bool visited[1501][1501][5] = {};

ll solve() {
    int n; cin >> n;
    int ax, ay; cin >> ax >> ay;
    int bx, by; cin >> bx >> by;
    ax--; ay--; bx--; by--;
    if(ax == bx && ay == by) return 0;
    vector<string> board(n);
    cin >> board;

    vector<array<int, 2>> dirs = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}}; //Bottom right, bottom left, up right, up left
    vector<vector<vector<int>>> dist(n, vector<vector<int>> (n, vector<int>(5, inf)));
    dist[ax][ay][4] = 0;
    queue<array<int, 4>> q; q.push({ax, ay, 0, 4});
    int numMoves = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto curr = q.front(); q.pop();
            if(curr[2] != dist[curr[0]][curr[1]][curr[3]]) continue;
            for(int i = 0; i < 4; ++i) {
                int x = curr[0] + dirs[i][0];
                int y = curr[1] + dirs[i][1];

                if(x < 0 || x > board.size()-1) continue;
                if(y < 0 || y > board[0].size()-1) continue;
                if(board[x][y] == '#' || visited[x][y][i] == 1) continue;
                
                int nd = curr[2] + (i != curr[3]);
                if(nd < dist[x][y][i]) {
                    dist[x][y][i] = nd;
                    q.push({x, y, nd, i});
                }
            }
        }
    }

    int res = *min_element(dist[bx][by].begin(), dist[bx][by].end());
    return (res == inf) ? -1 : res;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cout << solve();
}



// priority_queue<state> pq;
// dist[ax][ay][4] = 0;
// pq.push( {0, ax, ay, 4} );
// while (!pq.empty()) {
//     state s = pq.top();
//     pq.pop();
//     if (-s[0] != dist[s[1]][s[2]][s[3]]) continue;
//     for (int i : {0,1,2,3}) {
//         int r = s[1] + dirs[i][0];
//         int c = s[2] + dirs[i][1];
//         if (r < 0 || r >= N || c < 0 || c >= N) continue;
//         if (grid[r][c] == '#') continue;
//         int nd = -s[0] + (i != s[3]);  // new depth
//         if (nd < dist[r][c][i]) {
//             dist[r][c][i] = nd;
//             pq.push( {-nd,r,c,i} );
//         }
//     }
// }