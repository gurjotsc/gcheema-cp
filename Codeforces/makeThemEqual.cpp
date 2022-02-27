#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> m;
vector<int> dist(1001, 0);
void bfs() {
    //preproccess graph distancese
    queue<pair<int, int>> q; //stores number and distances
    q.push({1, 0});
    dist[1] = 0;
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            auto curr = q.front(); q.pop();
            int div = 1;
            while(div*div <= curr.first) { //O(sqrt(n))?
                ll x = curr.first + (curr.first/div);
                ll y = curr.first + (curr.first/(curr.first/div));
                if(x < 1001 && !dist[x]) {
                    q.push({x, curr.second+1});
                    dist[x] = curr.second + 1;
                }
                if(y < 1001 && !dist[y]) {
                    q.push({y, curr.second+1});
                    dist[y] = curr.second + 1;
                }
                ++div;
            }
        }
        

    }
}



ll solve() {
    int n, k; cin >> n >> k;
    vector<ll> b(n);
    vector<ll> c(n);
    vector<ll> dp(k+1, -1);
    ll res = 0ll;
    for(auto& i : b) cin >> i;
    for(auto& i : c) cin >> i;
    
    dp[0] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = k; j >= 0; --j) {
            if(dp[j] == -1 || j+dist[b[i]] > k) continue;
            auto idx = j+dist[b[i]];
            dp[idx] = max(dp[idx], dp[j] + c[i]);
            res = max(res, dp[idx]);
        }
    return res;
}
                     
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t; cin >> t;
    bfs();
    while(t--) cout << solve() << "\n";
    
}