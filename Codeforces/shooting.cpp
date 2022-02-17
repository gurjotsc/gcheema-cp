#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool sortcan(vector<int>& v1, vector<int>& v2) {
    if(v1[0] == v2[0]) return v1[1] <= v2[1];
    else return v1[0] >= v2[0];
    
}

int main() {
    int n; cin >> n;
    vector<vector<int>> cans(n, vector<int> (2));

    for(int i = 0; i < n; ++i) {
        cin >> cans[i][0];
        cans[i][1] = i;
    }
    sort(cans.begin(), cans.end(), sortcan);

    int res = 1;
    int cansShot = 1;
    for(int i = 1; i < n; ++i) res += ((cans[i][0] * (cansShot++)) + 1);
    cout << res << endl;

    for(int i = 0; i < n; ++i) cout << cans[i][1]+1 << " ";

}