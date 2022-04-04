#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
template<typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
     for (auto& item : data) input >> item;
     return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data) {
     for (const T& x : data) output << x << " " ;
     return output;
}

int solve() {

    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        int p = 0, m = 0;
        string curr = "";
        for(int j = i; j < n; ++j) {
            curr += s[j];
            (curr.back() == '+') ? ++p : ++m;
            int x = 2;
            while (x <= m) {
                if(m-(m/x) == p+(x/2)) {
                    ++res;
                    break;
                }
                x+=2;
            }

        }
    }

    return res;

}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}