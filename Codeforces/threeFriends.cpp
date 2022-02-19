#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    ll q; cin >> q;
    while(q--) {
        vector<ll> dist(3);
        for(auto& i : dist) cin >> i;
        sort(dist.begin(), dist.end());
        
        if(dist[0] != dist[1]) ++dist[0];
        else if(dist[0] + 1 <= dist[2]){
            ++dist[0];
            ++dist[1];
        }

        if(dist[2] != dist[1]) --dist[2];
        else if(dist[2] - 1 >= dist[0]) {
            --dist[2];
            --dist[1];
        }
        cout << (dist[2] - dist[1]) + (dist[2] - dist[0]) + (dist[1] - dist[0]) << endl;
    }
}