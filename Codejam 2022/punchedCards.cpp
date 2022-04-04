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

    int r, c; cin >> r >> c;

    string s = "";
    s += '.'; s += '.';
    for(int i = 0; i < c*2-1; ++i) s += (i%2) ? '-' : '+';
    cout << s;
    s = "";
    s += '.'; s += '.';
    for(int i = 0; i < c*2-1; ++i) s += (i%2) ? '.' : '|';
    cout << s;
    while(r--) {
        if(r == 1) {
            s = "";
            for(int i = 0; i < c*2+1; ++i) s += (i%2) ? '-' : '+';
            cout << s; return;
        }
        s = "";
        for(int i = 0; i < c*2+1; ++i) s += (i%2) ? '-' : '+';
        cout << s;
        s = "";
        for(int i = 0; i < c*2-1; ++i) s += (i%2) ? '.' : '|';
        cout << s;        
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    int cnt = 1;
    while (t--) {
        cout << "Case #" << cnt << ":\n";
        solve();
        cout << "\n";
        ++cnt;
    }
}