#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    ll n; cin >> n;
    ll res = 0;
    ll i = 1;
    while(n >= (i*(i+1)/2)) {
        ++res;
        n -= (i*(i+1)/2);
        ++i;
    }
    cout << res;
}