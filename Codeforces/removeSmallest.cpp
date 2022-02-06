#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(n == 1) {
            cout << "YES" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        for(int i = 1; i < n; ++i) {
            if (a[i] - a[i-1] > 1){
                cout << "NO" << endl;
                break;
            }
            else if (i == n-1) cout << "YES" << endl;
        }

    }
}