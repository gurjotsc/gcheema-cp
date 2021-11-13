#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector< tuple<int,int,int> > prefix(n+1);

    for (int i = 1; i < n+1; ++i) {
        int temp; cin >> temp;
        prefix[i] = prefix[i-1];
        if(temp == 1) get<0>(prefix[i])++;
        if(temp == 2) get<1>(prefix[i])++;
        if(temp == 3) get<2>(prefix[i])++;
    }

    for (int i = 0; i < q; ++i) {
        tuple<int, int, int> temp = {0,0,0};
        int a, b;
        cin >> a >> b;
        get<0>(temp) = get<0>(prefix[b]) - get<0>(prefix[a-1]);
        get<1>(temp) = get<1>(prefix[b]) - get<1>(prefix[a-1]);
        get<2>(temp) = get<2>(prefix[b]) - get<2>(prefix[a-1]);
        cout << get<0>(temp) << " " << get<1>(temp) << " " << get<2>(temp) << "\n";
    }
    return 0;
}
