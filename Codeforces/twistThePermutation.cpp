#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


void solve() {
    int n; cin >> n;
    vector<int> res(n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = n; i > 0; --i) {
        int currIdx;
        for(int j = 0; j < n; ++j)
            if(a[j] == i) {
                currIdx = j;
                break;
            }
        
        vector<int> temp(i);
        int shift = (i-1)-currIdx; // How far away is the currIdx from where its supposed to be (distance)
        //the shift+j give you the j shifted to the right shift times
        for(int j = 0; j < i; ++j) temp[(shift + j)%i] = a[j]; //Note negative%positve is a positive

        for(int j = 0; j < i; ++j) a[j] = temp[j];
        
        //Think about it this way
        //On the first iteration when i == n;
        //the currIndex SHOULD be in index n-1
        //By taking the currIndex, it tell you how far away it is from the beginning
        //Then add 1 to it to push it back into the final position
        //The next time you repeat the problem, you are still doing the same thing except i == n-1 and so on.
		//We do % i in case its already in the right position
        if(i != 1) res[i-1] = (currIdx + 1)%i;
        else res[i-1] = 0;
    }

    for(auto& i : res) cout << i << " ";

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}