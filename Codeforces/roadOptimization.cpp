#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
                     
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n, l, k; cin >> n >> l >> k;
    vector<ll> d(n+1);
    vector<ll> a(n+1);
    vector<vector<ll>> dp (n+1, vector<ll>(k+1, inf));
    for(ll i  = 1; i <= n; ++i) cin >> d[i];
    for(ll i  = 1; i <= n; ++i) cin >> a[i];

    dp[1][0] = 0ll;
	//calcualte distance without removing any signs
    for(ll i = 2; i <= n; ++i) dp[i][0] = dp[i-1][0] + (a[i-1]*(d[i] - d[i-1])); 

    for(ll i = 2; i <= n; ++i) {
        for(ll j = 1; j <= k; ++j) {
            for(ll pre = i - 1; pre >= 1; --pre) {
                //dp[i][j] represents the fastest possible way to get to i if we remove AT MOST j signs
                ll used = (i)-(pre+1);
                ll remaining = j-used;
                //since used represents us deleting all the signs from pre+1 to i-1
                //remaining is going to give us HOW MUCH EXTRA SIGNS WE HAVE LEFT TO REMOVE AFTER REMOVING pre+1 TO i-1
                //1 2 3 ...pre pre+1 pre+2... i-1
                if(remaining < 0ll) continue;
                //dp[pre][remaining] represent the faststed way to get to pre using "remaining" sign deletions...from here we have "used" left signs to delete pre+1 to i-1
                //another way to think about it is we've used "remaining" deletions in dp[pre][remaining] and we assume we deleted all the signs after that
                else dp[i][j] = min(dp[i][j],
                                    dp[pre][remaining] + ((d[i]-d[pre])*(a[pre])));
            }

        }
    }

    ll res = inf;
    for(ll j = 0ll; j <= k; ++j) {
        for(ll pre = n; pre >= 1; --pre) {
            ll used = ((n+1) - (pre+1));
            ll remaining = j-used;
            if(remaining < 0ll) continue;
            res = min(res, 
                      dp[pre][remaining] + ((l-d[pre])*a[pre]));
        }
    }
    cout << res;


}
