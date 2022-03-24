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

void solve() {
    ll n; cin >> n;
    vector<ll> b(n);
    vector<ll> a(n);
    ll bSum = 0ll;
    ll aSum;
    
    cin >> b;
    for(auto& i : b) {
        bSum += i;
        //if there occurs a number that is less than the sum up to n, then return "NO"
        //This is because even if all of a was 1, since all coefficients of 1...n will be multiple in a to get a[i], b[i] should at least be the sum of 1...n
        if(i < ((n*(n+1))/2)) {
            cout << "NO";
            return;
        }
    }
    
    if(n==1) {
        cout << "YES\n" << b[0];
        return;
    }

    //since we rotate clockwise
    //b[0] = 1*a[0] + 2*a[n-1] + 3*a[n-2] + ... + n*a[1]
    //b[n-1] = 1*a[n-1] + 2*a[n-2] + 3*a[n-3] + ... + n*a[0]
    //b[n-2] = 1*a[n-2] + 2*a[n-3] + 3*a[n-4] + ... + n-1*a[0] + n*a[n-1]
    //...
    //SUM(b) = (1+2+3+4+...+n)*(a[0]+a[1]+...+a[n-1])
    //This is because going around the clock, each coeffecient is used exactly once for each a[i]
    //Thus
    // SUM(b)/(1+2+3+4+..+n) = (a[0]+a[1]+...+a[n-1]) = SUM(a)
    
    //Mathematically, this b vector doesn't correspond to an A vector since a would need a double then, hence we cout "NO"
    if(bSum%((n*(n+1))/2)) {
        cout << "NO";
        return;
    }
    else aSum = bSum/((n*(n+1))/2);

    //b[0] = 1*a[0] + 2*a[n-1] + 3*a[n-2] + ... + n*a[1]
    //b[n-1] = 1*a[n-1] + 2*a[n-2] + 3*a[n-3] + ... + n*a[0]
    //b[n-1]-b[0] = 1*a[n-1] + 2*a[n-2] + 3*a[n-3] + ... + n*a[0]
    //            - 1*a[0] + 2*a[n-1] + 3*a[n-2] + ... + n*a[1]
    //          = -a[n-1] - a[n-2] - ... - a[1] + (n-1*a[0])
    //     aSum + "                                      "
    //= a[0] + a[1] + a[2]+...+a[n-1] + "                "
    //= a[0] + (n-1*a[0])
    //= n*a[0]

    for(ll i = n-1; i >= 0; --i) {
        ll curr = b[i] - b[(i+1)%n] + aSum;
        if(curr%n || curr <= 0) {
            cout << "NO";
            return;
        }
        a[(i+1)%n] = curr/n;
    }

    cout << "YES\n" << a;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}