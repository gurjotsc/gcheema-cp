#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int n; cin >> n;
    int available = 0, res = 0;
    while(n--) {
        int temp; cin >> temp;
        if(temp > 0) available += temp;
        else {
            if(available) --available;
            else ++res;
        }
    }
    cout << res;
}