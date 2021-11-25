#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
#define ll long long

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n; cin >> n;
    vector<int> w(2*n);
    int res = INT_MAX;

    for(int i = 0; i < 2*n; ++i) cin >> w[i];
    sort(w.begin(), w.end());

    //for loops for i and j assume that pair i and j (this overs all possibilites) are the two going in the individual kayak
    for(int i = 0; i < 2*n; ++i) {
        for(int j = i+1; j < 2*n; ++j) {
            int currInstability = 0;
            int prevDuo = 0; //stores the first person in the board (the person with the lower weight)

            for(int k = 0; k < 2*n; ++k) { //iterates through the entire thing to calculate currInstability assuming i and j were in the single kayaks
                if(k == i || k == j) continue; //if k is a person in an individual kayak
                if(!prevDuo) prevDuo = w[k];
                else {
                    currInstability += abs(w[k] - prevDuo);
                    prevDuo = 0;
                }
            }
            res = min(res, currInstability);
        }
    }
    cout << res;
}
