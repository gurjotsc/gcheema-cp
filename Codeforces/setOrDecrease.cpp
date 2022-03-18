#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


ll accFloor(ll num, ll div) {
    ll val = num/div;
    if(val*div > num) --val;
    return val;
}

ll solve() {
    ll n, k; cin >> n >> k;
    ll sum = 0ll;
    vector<ll> a(n+1); //one-indexed
    vector<ll> pre(n+1); //one-indexed
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    if(sum <= k) return 0ll;
    if(n == 1) return a[1]-k;
    sort(a.begin(), a.end());
    
    for(ll i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i];

    ll mn = inf;
    for(ll i = 0ll; i < n; ++i) {
        //Sum of array after decreasing the minimum value and assigning it to i maximum values
        //(a[1]-x)*(i+1)+pre[n-i]-a[1] <= k
        //(i+1) because there are i reassignments to a[1]-x + 1 for the origonal minimum value
        //solve for x assuming we reassign i values for all 0 <= i < n (note when solving for x we set it = to k not <= k so that we can minimize x)
        ll num = (k - pre[n-i] + a[1]);
        ll div = i+1;
        ll x = a[1] - accFloor(num, div);
        //x will be negative when you need to increase a[i] to reach k (in this case this is just the minimum, and we do not need to subtract x from a[i] since we can just rplace the i msximums with this value to get a sum <= k)
        mn = min(mn, max(0ll,x)+i);
    }

    return mn;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}


// 0 1 1 1 1 2 2 3 
// 0 1 2 3 4 6 8 11
// 0 1 1 1 2 2 0 = 7

// 8 - 11 + 1 = -2/1 = -2 = 2 = 2
// 8 - 10 + 1 = -1/1 = -1 = 1 = 2
// 8 - 9 + 1 = 0/1 = 0 = 0 + 2