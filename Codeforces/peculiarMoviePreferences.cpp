#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


string solve() {
    int n; cin >> n;
    unordered_set<string> seen;
    vector<string> s(n);
    for(auto& i : s) cin >> i;
    for(int i = 0; i < n; ++i) {
        string temp = s[i]; reverse(temp.begin(), temp.end());
        if(seen.count(temp)) return "YES";
        else seen.insert(s[i]);

        if(temp.size() == 1) return "YES";
        else if (temp.size() == 2){
            //ba
            //abcba
            //temp2 == ab
            if(temp[0] == temp[1]) return "YES";
            string temp2 = "";
            temp2 += s[i][1];
            temp2 += s[i][0];
            for(int j = 0; j < 26; ++j) {
                string find = temp2;
                find += ('a'+j);
                if(seen.count(find)) return "YES";
            }
        } 
        else if(temp.size() == 3) {
            string temp2 = "";
            temp2 += s[i][2];
            temp2 += s[i][1];
            if(seen.count(temp2)) return "YES";
            if(temp[0] == temp[1] && temp[1] == temp[2]) return "YES";
			if(temp[0] == temp[2]) return "YES";
        }

    }
    return "NO";
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}