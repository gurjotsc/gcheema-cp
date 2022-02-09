#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    string s; cin >> s;
    int l = 0, u = 0;
    for(auto c : s){
        if(c >= 'a') ++l;
        else ++u;
    }
    
    for(auto &c : s) {
        if(l >= u) c = tolower(c);
        else c = toupper(c);
    }
    cout << s;
}