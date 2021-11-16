#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t;

    while(t--) {
        /*
        If a subarray A's sum is equal to it length, it's the equivalent of r-l=Ar-Al, r-Ar=l-Al, or Ar-r=Al-l
        Therefore we simply need to count the occurences of each value (using the formula above) and them to the solution.
        */
        int n; cin >> n;
        string s; cin >> s;
        int prefixSum = 0;
        unordered_map<int, int> m;
        ++m[prefixSum];
        ll ans = 0;
        for(int i = 1; i < n+1; ++i) {
            prefixSum += (int)(s[i-1] - '0');
            ans += m[prefixSum - i]++;
            //find if there exists and Ar - r = Al - l
            //Ar = prefixSum and r = i (1-indexed)
        }
        cout << ans << "\n";
    }
}
