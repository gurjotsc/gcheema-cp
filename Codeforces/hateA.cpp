#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    string t; cin >> t;
    int n = t.size();
    int a = count(t.begin(), t.end(), 'a');
    
    string tPrime = "";
    for(int i = 0; i < n; ++i) 
        if(t[i] != 'a') tPrime += t[i];
    int nPrime = tPrime.size();
    
    string s = "";
    string check = "";
    for(int i = 0; i < (n - (nPrime/2)); ++i) {
        s += t[i];
        if(s[i] != 'a') check += t[i];
    }

    int j = n-(nPrime/2)-1;    

    for(int i = 0; i < check.size(); ++i) {
        if(check[i] != t[j]) {
            cout << ":(";
            return -1;
        } 
        else ++j;
    }
    cout << s;   

}