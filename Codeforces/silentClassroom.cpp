#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int n; cin >> n;
    vector<int> a(26);
    vector<int> b(26);
    int res = 0;
    while(n--) {
        string curr; cin >> curr;
        char first = curr[0];
        if(a[first - 'a'] <= b[first - 'a']) ++a[first - 'a'];
        else ++b[first - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        int n = a[i] - 1;
        res += ((n*(n+1))/2);
        n = b[i] - 1;
        res += ((n*(n+1))/2);
    }
    cout << res;
}