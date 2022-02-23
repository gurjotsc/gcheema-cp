#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        vector<int> idx;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i]%2 && i > 0 && i < n-1) idx.push_back(i);
        }

        for(int i = 1; i < n-1; ++i) {
            if(a[i]%2) continue;
            else {
                a[i] -= 2;
                ++res;
                if(idx.size()){
                    if(idx[idx.size()-1] > i) {
                        ++a[0];
                        ++a[idx[idx.size()-1]];
                        idx.pop_back();
                    }
                    else {
                        ++a[n-1];
                        ++a[idx[idx.size()-1]];
                        idx.pop_back();
                    }

                }
                else {
                    ++a[0];
                    ++a[n-1];
                }
            }
        }
        if(idx.size()) cout << -1 << endl;
        else {
            for(int i = 1; i < n-1; ++i) res += (a[i]/2);
            cout << res << endl;
        }
    }
}