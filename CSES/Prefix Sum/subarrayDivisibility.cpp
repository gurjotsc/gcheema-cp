#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> prefix(n+1);
    map<ll, ll> m;
    int ans = 0;
    prefix[0] = 0;
    for(int i = 1; i < n+1; ++i) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }
    //if we were to O(n^2) this we could check the entire array for a prefix sum where prefix[j] - prefix[i] % n == 0
    //instead we use a map to store how many times we have seen each remainder
    //You can think of this as performing a prefix[j] - prefix[i].
    //If two prefixes have the same remainder, then that means the elements between them % n == 0 since the numbers from (0,i) are getting counted in prefix[j]
    //by using the mod method we are effiectivley "removing elemnts" before the subarray we want.
    for(auto i : prefix) {
        i = abs(i) % n;
        if(m.find(i) != m.end()) ans += m[i]++;
        else m[i] = 1;
    }

    cout << ans;
    return 0;

}
