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
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, qSz; cin >> n >> qSz;
    vector<int> b(n); cin >> b;
    vector<pii> q(qSz);
    for(auto& i : q) cin >> i.first >> i.second;
    vector<int> pre1(n); 
    vector<int> pre2(n);
    vector<int> pre3(n);

    pre1[0] = (b[0] == 1) ? 1 : 0;
    pre2[0] = (b[0] == 2) ? 1 : 0;
    pre3[0] = (b[0] == 3) ? 1 : 0;

    for(int i = 1; i < n; ++i) {
        pre1[i] = pre1[i-1]+(b[i] == 1);
        pre2[i] = pre2[i-1]+(b[i] == 2);
        pre3[i] = pre3[i-1]+(b[i] == 3);
    }
    
    for(auto& i : q) {
        int a = i.first-1, b = i.second-1;
        if(a) {
            cout << pre1[b]-pre1[a-1] << " "
                 << pre2[b]-pre2[a-1] << " "
                 << pre3[b]-pre3[a-1];    
        }
        else cout << pre1[b] << " " << pre2[b] << " " << pre3[b];
        cout << "\n";
    }


}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    solve();
}