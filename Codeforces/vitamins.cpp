#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    int i = 0;
    vector<string> vitamins(n);
    vector<int> costs(n);
    int minA = 10e6, minB = 10e6, minC = 10e6;
    int res;
    while(i < n) {
        cin >> costs[i];
        cin >> vitamins[i];
        if(vitamins[i] == "A") minA = min(minA, costs[i]);
        else if(vitamins[i] == "B") minB = min(minB, costs[i]);
        else if(vitamins[i] == "C") minC = min(minC, costs[i]);
        ++i;
    }
    res = minA+minB+minC;
    cout << res;
    for(i = 0; i < n; ++i) {
        if(vitamins[i].size() == 3) res = min(res, costs[i]);
        if(vitamins[i].size() == 2) {
            unordered_set<char> temp;
            for(auto c : vitamins[i]) temp.insert(c);
            int curr = res;
            if(temp.find('A') != temp.end()) curr -= minA;
            if(temp.find('B') != temp.end()) curr -= minB;
            if(temp.find('C') != temp.end()) curr -= minC;
            res = min(res, curr + costs[i]);
        }
    }
    if(res >= 10e6) cout << "-1";
    else cout << res;
}
