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


string solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    cin >> a;
    if(n==1) (!a[0] || a[0] == 1) ? "YES" : "NO";
    sort(a.begin(), a.end());
    for(int i = n-1; i > 0; --i)
        if(a[i] - a[i] > 1) 
            return "NO";
    return "YES";
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}
