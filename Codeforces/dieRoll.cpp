#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int y, w; cin >> y >> w;
    int num = (6 - max(y, w) + 1);
    int den = 6;
    if(num == 3) {
        num = 1;
        den = 2;   
    }
    else if (!(num%2)){
        num /= 2;
        den = 3;
    }

    if(num == den) {
        num = 1;
        den = 1;
    }
    cout << num << "/" << den;
}