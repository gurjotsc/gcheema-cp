#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int team = 0, team1W = 0, team2L = 0, team1L = 0, team2W = 0, turnsLeft1 = 5, turnsLeft2 = 5;
        for(int i = 0; i < 10; ++i) {
            if(!team) { // team1's turn
                turnsLeft1--;
                if(s[i] != '0') ++team1W;
                if(s[i] == '1') ++team1L;
            }
            else { //team 2's turn
                turnsLeft2--;
                if(s[i] != '0') ++team2W;
                if(s[i] == '1') ++team2L;
            }
            if(team1W > (team2L + turnsLeft2) || team2W > (team1L + turnsLeft1)) {
                cout << i+1 << endl;
                break;
            }
            team = (team+1)%2;
        }
        if(team1W == team2L && team1W == team2W && team2W == team1L) cout << 10 << endl;
    }
}
