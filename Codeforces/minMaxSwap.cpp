#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        int am = 0, bm = 0;
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;

        for(int i = 0; i < n; ++i) {
            if(a[i] > b[i]) swap(a[i], b[i]);
            am = max(am, a[i]);
            bm = max(bm, b[i]);
        }
        
        cout << am * bm << endl;
    }
}