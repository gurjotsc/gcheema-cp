#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    string res = "";
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '.') res += '0';
        if(s[i] == '-') {
            if(s[++i] == '.') res += '1';
            else res += '2';
        }
    }
    cout << res;

}
