#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];

        if(n <= 2) {
            cout << 0 << endl;
            continue;
        }
        int res = INT_MAX;
        //for each pair, 
            //if the current k does not follow the arithmetic progression of the pair i,j (line 29)
                //then we have to change this number 
		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {
				int count = 0; //stores num changes
				for(int k = 0; k < n; ++k) {
					if(k == i || k == j) 
                        continue;
                    //the difference between k and i multiplied with the num elements between j and k  should equal the same for k and j
                    //in arithmetic progression, each number has the same diference from the number previous to it so the above case
                    //should be true. If its not then we increment count since we need to change the number.
					if(((a[i]-a[k])*(j-k)) != ((a[j]-a[k])*(i-k)))
                        ++count;
				}
                res = min(res, count);
			}
		}
        cout << res << endl;
	}
}