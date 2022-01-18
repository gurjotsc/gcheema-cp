#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        //if n-1 is ODD keep in mind the gcd of an odd and 2 is always 1
        //n-3 is ODD
        if((n-1)%2) cout << n-3 << " " << 2 << " " << 1 << endl;
        //if n-1 is EVEN, then keep in mind that integers r and r+2 can't have a gcd greater than 1 assuming that r is odd
        else {
            //since n-1/2 is EVEN here, then dividing n-1 by 2 and then subtracting 1 and adding 1 to gives us an odd r and r+2 which satisfies the above conditions
            if(!(((n-1)/2)%2)) cout << ((n-1)/2)-1 << " " << ((n-1)/2)+1 << " " << 1 << endl;
            //since n-1/2 is ODD here, then dividing n-1 by 2 and then subtracting 1 and adding 1 to gives us an EVEN r and r+2 which does NOT satisfies the above conditions
            //instead we do -2 and +2
            else cout << ((n-1)/2)-2 << " " << ((n-1)/2)+2 << " " << 1 << endl;
        }
    }
}