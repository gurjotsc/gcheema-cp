#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     

int solve() {
    int n; cin >> n;
    int k = 0;
    string s; cin >> s;
    string temp = s;
    
    sort(begin(temp), end(temp));
    for (int i = 0; i < n; ++i) 
        if(temp[i] != s[i]) ++k;
    
    return k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}