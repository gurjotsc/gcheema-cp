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



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<char, ll>> v(n);
    vector<int> liar(n);
    int res = 0;
    for(int i = 0; i < n; ++i) {
        char info; cin >> info;
        ll pi; cin >> pi;
        v[i] = {info, pi};

        for(int j = 0; j < i; ++j) {
            if(info == 'G') {
                if(v[j].first == 'L') {
                    if(v[j].second < pi && !liar[j]) {
                        ++res;
                        liar[j] = 1;
                    }
                }
            }
            else {
                if(v[j].first == 'G') {
                    if(v[j].second > pi && !liar[j]) {
                        ++res;
                        liar[j] = 1;
                    }
                }
            }
        }
    }

    cout << min(res, n-res);
}