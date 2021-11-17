#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> prefix(n+1); //stores the gcd of all elments to the left of a given i
    //we store n+2 here so that we can one index and have a buffer value of 0 at the end of the array
    // if we did n+1 then suffix[i] = buffer value of 0 and suffix[0] = gcd of all the elements to the right of the array
    //with n+1 suffix[0] = 0 and suffix[1] = gcd of all the elements to the right of the array
    vector<int> suffix(n+2); //stores the gcd of all elments to the right of a given i
    vector<int> a(n+1);

    //gcd of (num, 0) is just num since 0 can be divded by anything
    prefix[0] = 0;
    suffix[n+1] = 0;

    for(int i = 1; i < n+1; ++i) cin >> a[i];

    for(int i = 1; i < n+1; ++i) prefix[i] = __gcd(prefix[i-1], a[i]);
    for(int i = n; i >= 1; --i) suffix[i] = __gcd(suffix[i+1], a[i]);

    int ans = INT_MIN;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, __gcd(prefix[i-1], suffix[i+1]));
    }

    cout << ans;

}
