#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, cnt1 = 0;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int temp; cin >> temp;
            if(temp) ++cnt1;
        }
        int k = n/2;
        if(cnt1 > n/2) {
            if((n/2)%2) ++k; //if n/2 is odd
            cout << k << endl;
            for(int i = 0; i < k; ++i) cout << "1 ";
        }
        else {
            cout << k << endl;
            for(int i = 0; i < k; ++i) cout << "0 ";
        }
        cout << endl;
    }
}
