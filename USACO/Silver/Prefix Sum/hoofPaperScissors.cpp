#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n; cin >> n;
    vector< tuple<int,int,int> > prefix(n);
    char temp; cin >> temp;
    if(temp == 'H') get<0>(prefix[0]) = ++get<0>(prefix[0]);
    if(temp == 'P') get<1>(prefix[0]) = ++get<1>(prefix[0]);
    if(temp == 'S') get<2>(prefix[0]) = ++get<2>(prefix[0]);

    for(int i = 1; i < n; ++i) {
        char temp; cin >> temp;
        prefix[i] = prefix[i-1];
        if(temp == 'H') get<0>(prefix[i]) = ++get<0>(prefix[i]);
        if(temp == 'P') get<1>(prefix[i]) = ++get<1>(prefix[i]);
        if(temp == 'S') get<2>(prefix[i]) = ++get<2>(prefix[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        //iterate through and assuming you pick one first, calculate assuming you pick a different one second for the remainder of the vector
        //pick hoof first
        ans = max(ans, get<0>(prefix[i]) + get<1>(prefix[n-1]) - get<1>(prefix[i]));
        ans = max(ans, get<0>(prefix[i]) + get<2>(prefix[n-1]) - get<2>(prefix[i]));
        //pick paper first
        ans = max(ans, get<1>(prefix[i]) + get<0>(prefix[n-1]) - get<0>(prefix[i]));
        ans = max(ans, get<1>(prefix[i]) + get<2>(prefix[n-1]) - get<2>(prefix[i]));
        //pick scissors first
        ans = max(ans, get<2>(prefix[i]) + get<0>(prefix[n-1]) - get<0>(prefix[i]));
        ans = max(ans, get<2>(prefix[i]) + get<1>(prefix[n-1]) - get<1>(prefix[i]));
    }

    cout << ans;
}
