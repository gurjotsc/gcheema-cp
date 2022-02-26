#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int n, k; cin >> n >> k;
    int res = 0;
    vector<int> d(n);
    unordered_map<int, int> m;
    for(auto& i : d) cin >> i;

    for(int i = 0; i < n; ++i) {
        cout << i << " " << (k-(d[i]%k)) << "\n";
        if(m.count((k-(d[i]%k)))) {
            --m[(k-(d[i]%k))];
            ++res;
        }
        else if(!(d[i]%k)) ++m[k];
        else ++m[d[i]%k];
    }
    cout << res*2 << "\n";

}