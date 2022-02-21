#include "bits/stdc++.h"
using namespace std;
using ll = long long;
                     
int main() {
    ll b, k; cin >> b >> k;
    vector<ll> a(k);
    ll n = 0ll;
    for(auto& i : a) cin >> i;
    for(ll i = k-1; i >= 0; --i) {
        // if(b == 99 && k == 30) {
        //     cout << i << " ";
        //     cout << a[k - i - 1] << " ";
        //     cout << pow(b, i);
        //     cout << endl;
        // }
        n += (a[k - i - 1] * pow(b, i));
    }
    if(n%2) cout << "odd";
    else cout << "even";
}