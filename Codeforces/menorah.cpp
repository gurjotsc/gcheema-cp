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

ll check(const string& a, const string& b, ll& n) {
    ll cnt01 = 0ll;
    ll cnt10 = 0ll;

    for(ll i = 0ll; i < n; ++i) {
        if(a[i] == '0' && b[i] == '1') ++cnt01;
        if(a[i] == '1' && b[i] == '0') ++cnt10;
    }

    if(cnt01 != cnt10) return inf;

    //each time there is a 01, you need to swap the 0 with another 1 in the array (i.e turning 101 into 110. First 101->011->110)
    //for the rest of the string (not the swapped values) to maintain its same values it takes 2 moves
    //hence the number of 01 and 10 occurances need to be the same so you could swap a 0 where there should be a 1 with a 1 that should be a 0
    return cnt01+cnt10;
}


ll update(string a, string b, ll& n, char test) {
    ll idx = -1;
    for(ll i = 0ll; i < n; ++i) {
        if(a[i] == '1' && b[i] == test) {
            idx = i;
            break;
        }
    }

    if(idx == -1) return inf;

    for(ll i = 0ll; i < n; ++i) {
        if(i == idx) continue;

        a[i] = (a[i] == '1') ? '0' : '1';
    }
    
    return check(a, b, n);
}

ll solve() {
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    if(a == b) return 0ll;

    //do a basic check
    ll ans = check(a, b, n);
    //if we hold a bit equal to another 1 in b then all the origonal 01 and 10's will fall to their correct positions (11 and 00).
    //perform the check again to see if there is a better answer that can be done in less operations
    //you don't need to update again because you would be reverting the ones that are good now and you would be --01 or --10 each time which is just simulating the problem in its whole (Im guessing this could work but there is no need also it would TLE)
    ans = min(ans, 1+update(a, b, n, '1')); //the plus 1 is for the operation to make the inital change
    //Same thing with 0
    ans = min(ans, 1+update(a, b, n, '0'));

    return (ans != inf) ? ans : -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}