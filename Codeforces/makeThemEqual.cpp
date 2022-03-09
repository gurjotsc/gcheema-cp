#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;
using ll = long long;

map<int, int> m;
vector<int> dist(1001, -1);
void bfs() {
    //preproccess graph distancese
    queue<int> q; //stores number and distances
    q.push(1);
    int depth = 0;
    dist[1] = depth;
    while(!q.empty()) {
        int n = q.size();
        while(n--) {
            int curr = q.front(); q.pop();
            int div = 1;
            while(div*div <= curr) { //O(sqrt(n))?
                ll x = curr + (curr/div);
                ll y = curr + (curr/(curr/div));
                if(x < 1001 && dist[x] == -1) {
                    q.push(x);
                    dist[x] = depth + 1;
                }
                if(y < 1001 && dist[y] == -1) {
                    q.push(y);
                    dist[y] = depth + 1;
                }
                ++div;
            }
        }
        ++depth;
    }
}



ll solve() {
    int n, k; cin >> n >> k;
    vector<ll> b(n);
    vector<ll> c(n);
    vector<ll> dp(k+1, -1);
    vector<int> w(n);
    ll res = 0ll;
    for(auto& i : b) cin >> i;
    for(auto& i : c) cin >> i;
    for(int i = 0; i < n; ++i) w[i] = dist[b[i]];
    dp[0] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = k; j >= 0; --j) {
            if(dp[j] == -1 || j+w[i] > k) continue;
            auto idx = j+w[i];
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