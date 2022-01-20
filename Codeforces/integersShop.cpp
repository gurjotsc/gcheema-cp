#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll minL, maxR , valL, valR, maxInts, minVal;
        for(int i = 0; i < n; ++i){
            ll l, r, c;
            cin >> l >> r >> c;
            if(!i) {
                minL = l; maxR = r;
                valL = c; valR = c;
                minVal = c;
                maxInts = r-l+1;
                cout << c << endl;
            }
            else {
                if(l == minL) valL = min(valL, c);
                else if(l < minL) valL = c;
                if(r == maxR) valR = min(valR, c);
                else if(r > maxR) valR = c;
                minL = min(minL, l);
                maxR = max(maxR, r);
                //case where the single segment is lower than minL and higher than maxR
                if(r-l+1 > maxInts) {
                    maxInts = r-l+1;
                    minVal = c;
                }
                //case where the single segment is equal to minL and equal to maxR
                else if (r-l+1 == maxInts) minVal = min(minVal, c);
                ll res = valL + valR;
                //case where chosing two segments and one segment have the same maxR and minL. Choose the cheaper option
                if(maxR-minL+1 == maxInts) res = min(res, minVal);
                cout << res << endl;
            }


        }
    }    
}