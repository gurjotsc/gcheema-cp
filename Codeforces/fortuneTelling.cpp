#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


string solve() {
    ll n, x, y; cin >> n >> x >> y;
    ll alice = x, bob = x+3;
    //vector<ll> a(n);
    ll sum = 0ll;
    while(n--) {
        ll temp; cin >> temp;
        sum += temp;
    }

    if(sum%2) {
        if(alice%2 && !(y%2)) return "Alice";
        if(!(alice%2) && y%2) return "Alice";
    }
    else {
        if(alice%2 && y%2) return "Alice";
        if(!(alice%2) && !(y%2)) return "Alice";
    }

    return "Bob";



    
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}