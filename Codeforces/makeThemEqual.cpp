#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> m;
vector<int> distances(1001, 0);
void bfs() {
    //preproccess graph distancese
    queue<pair<int, int>> q; //stores number and distances
    q.push({1, 0});
    distances[1] = 0;
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        int div = 1;
        while(div <= curr.first) { //O(sqrt(n))?
            if(curr.first + (curr.first/div) < 1001 && !distances[curr.first + (curr.first/div)]) {
                q.push({curr.first + (curr.first/div), curr.second + 1});
                distances[curr.first + (curr.first/div)] = curr.second + 1;
            }
            ++div;
        }

    }
}

int solve() {
    int n, k; cin >> n >> k;
    vector<int> b(n);
    vector<int> c(n);
    vector<int> dist(n);
    vector<int> dp(k);
    int res = 0;
    for(auto& i : b) cin >> i;
    for(auto& i : c) cin >> i;
    bfs();
    for(int i = 0; i < 100; ++i) cout << dist[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; ++i) dist[i] = distances[b[i]];
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            if(j + dist[i] < k) {
                dp[j + dist[i]] = dp[j] + c[i];
                res = max(res, dp[j + dist[i]]);
            }
        }
    }
    return res;

}
int main() {
    int t; cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
}

// 1 7 5 2
// 2 6 5 2

// distnaces
// 0 0 1 2 3 4 3 5