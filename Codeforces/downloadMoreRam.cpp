#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int res = k;
        vector<int> a(n);
        vector<int> b(n);
        for(auto& i : a) cin >> i;
        for(auto& i : b) cin >> i;
        
        bool check = true;
        while(check) {
            check = false;
            for(int i = 0; i < n; ++i){
                if(res >= a[i] && a[i] >= 0) {
                    check = true;
                    res += b[i];
                    a[i] = -1;
                    b[i] = -1;
                }
            }
        }


        cout << res << "\n";
    }
}