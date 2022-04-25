// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <bits/stdc++.h>
// using namespace std;
// using ll = int64_t;




// template<typename T>
// std::istream& operator >>(std::istream& input, std::vector<T>& data) {
//      for (auto& item : data) input >> item;
//      return input;
// }
// template <typename T>
// std::ostream& operator <<(std::ostream& output, const std::vector<T>& data) {
//      for (const T& x : data) output << x << " " ;
//      return output;
// }
// template <typename T>
// std::ostream& operator <<(std::ostream& output, const std::pair<T, T>& data) {
//     output << "{" << data.first << ", " << data.second << "}";
//     return output;
// }
// template <typename T, typename U>
// std::ostream& operator <<(std::ostream& output, const std::map<T, U>& data) {
//     for(auto it = data.begin(); it != data.end(); ++it) output << "{" << it->first << ", " << it->second << "} ";
//     return output;
// }
// template <typename T, typename U>
// std::ostream& operator <<(std::ostream& output, const std::unordered_map<T, U>& data) {
//     for(auto it = data.begin(); it != data.end(); ++it) output << "{" << it->first << ", " << it->second << "} ";
//     return output;
// }
// template <typename T>
// std::ostream& operator <<(std::ostream& output, const std::set<T>& data) {
//     for(auto it = data.begin(); it != data.end(); ++it) output << *it << " ";
//     return output;
// }
// template <typename T>
// std::ostream& operator <<(std::ostream& output, const std::unordered_set<T>& data) {
//     for(auto it = data.begin(); it != data.end(); ++it) output << *it << " ";
//     return output;
// }
// ll modPow(ll a, ll b, ll m) {
//     a %= m;
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }





// ll score(string S){
//     vector<ll> cnt(10);
//     iota(cnt.begin(), cnt.end(), 0);
//     for(char c : S) cnt[c - '0'] *= 10;
//     return accumulate(cnt.begin(), cnt.end(), 0);
// }
// int main(){
//     ll K;
//     string S, T;
//     cin >> K >> S >> T;
//     vector<ll> cnt(10, K);
//     for(char c : S + T) cnt[c - '0']--;
//     ll win = 0;
//     for(ll x = 1; x <= 9; x++) for(ll y = 1; y <= 9; y++){
//         S.back() = '0' + x;
//         T.back() = '0' + y;

//         if(x == 1 && y == 1) cout << score(S) << " " << score(T) << "\n";
//         if(score(S) <= score(T)) continue;
//         win += cnt[x] * (cnt[y] - (x == y));
//     }
//     const ll rem = 9 * K - 8;
//     cout << "\n" << double(win) / rem / (rem - 1) << endl;
// }







#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define all(x) begin(x), end(x)

template<typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data) {
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
    for(auto it = data.begin(); it != data.end(); ++it) output << *it << " ";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::unordered_set<T>& data) {
    for(auto it = data.begin(); it != data.end(); ++it) output << *it << " ";
    return output;
}
ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


ll score(string s) {
    vector<ll> cnt(10);
    iota(all(cnt), 0);
    for(auto c : s) cnt[c-'0'] *= 10; //score for each card thats face up
    return accumulate(all(cnt), 0);
}

double solve() {
    ll k; cin >> k;
    //S IS TAKAHASHI AND T IS AOKI I DON'T KNOW WHY THEY WOULD DO THIS
    //ACTUALLY MESSED ME UP FOR AN HOUR
    string s, t; cin >> s >> t;
    vector<ll> cnt(10, k);
    for(auto c : s+t) {
        if(c == '#') continue;
        cnt[c - '0']--; //card is face up
        //cout << c << cnt << "\n";
    }
    double numWins = 0;
    for(ll i = 1; i <= 9; ++i)
        for(ll j = 1; j <= 9; ++j) {
            s[4] = i+'0';
            t[4] = j+'0';
            //if(i == 2 && j == 1) cout << score(s) << " " << score(t) << "\n\n";
            //for this i,j pair, if it wins then...
            if(score(s) > score(t)) numWins += (cnt[i] * (cnt[j] - (i==j))); //for this i that wins, how many of this j are there? Thats how many times this combiniation can occur. if i == j jusst subtract a card since one card is being used for i
        }
    const ll rem1 = (9*k)-8; //how many possibilites are left for one of the last two slots
    const ll rem2 = (9*k)-9; //given that a card was put down, how many possibilities are left for the last card.
    const ll totalCombinations = rem1*rem2;
    return numWins/totalCombinations;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cout << solve();
}