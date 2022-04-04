#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::pair<T, T>& data) {
    output << "{" << data.first << ", " << data.second << "}";
    return output;
}
template <typename T, typename U>
std::ostream& operator <<(std::ostream& output, const std::map<T, U>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << "{" << it->first << ", " << it->second << "} ";
    return output;
}
template <typename T, typename U>
std::ostream& operator <<(std::ostream& output, const std::unordered_map<T, U>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << "{" << it->first << ", " << it->second << "} ";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::set<T>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << it->first << " ";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::unordered_set<T>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << it->first << " ";
    return output;
}


void solve() {
    vector<vector<int>> p(3, vector<int>(4));
    for(auto& i : p) cin >> i;

    vector<int> mins(4, 1e9);
    for(int i = 0; i < 3; ++i) mins[0] = min(mins[0], p[i][0]);
    for(int i = 0; i < 3; ++i) mins[1] = min(mins[1], p[i][1]);
    for(int i = 0; i < 3; ++i) mins[2] = min(mins[2], p[i][2]);
    for(int i = 0; i < 3; ++i) mins[3] = min(mins[3], p[i][3]);

    if(accumulate(mins.begin(), mins.end(), 0) < 1e6) cout << "IMPOSSIBLE";
    else if (accumulate(mins.begin(), mins.end(), 0) == 1e6) cout << mins;
    else {
        int goal = 1e6;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        c1 = min(mins[0], goal);
        goal -= c1;
        c2 = min(mins[1], goal);
        goal -= c2;
        c3 = min(mins[2], goal);
        goal -= c3;
        c4 = min(mins[3], goal);
        goal -= c4;
        cout << c1 << " " << c2 << " " << c3 << " " << c4;
        return;
    }



}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    int cnt = 1;
    while (t--) {
        cout << "Case #" << cnt++ << ": ";
        solve();
        cout << "\n";
    }
}