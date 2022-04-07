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
    int n; cin >> n;
    vector<int> a(n);
    cin >> a;

    int delFront = n, delBack = 0;
    int res = 0;
    for(int i = 0, l=-1; i <= n; ++i) { //l stores the answer l
        if(i == n || !a[i]){
            int cnt2 = 0;
            bool neg = false; //is this segment negative
            int left = -1, right = -1; //stores current l and r
            int left2 = 0, right2 = 0; //store prefix and suffix of magnitude changers (2's)
            for(int j = l+1; j < i; ++j) { //iterate from previous segment end to i
                neg = (a[j]<0) ? !neg : neg; //for each negative, the state flips
                if(a[j] < 0) {
                    right = j; //update ur segments asnwer
                    right2 = 0; //restart ur suffix count
                }
                
                if(abs(a[j]) == 2) {
                    ++cnt2; ++right2;
                    if(left == -1) ++left2; //prefix hasn't changed
                }

                if (a[j] < 0 && left == -1) left = j; //where we could start left if we delete prefix
            }
            if (neg) {
                //remove min(prefix2's, suffix2's)
                if (cnt2 - left2 > cnt2 - right2) {
                    right = i;
                    cnt2 -= left2; //delete prefix
                } else {
                    left = l;
                    cnt2 -= right2; //delete suffix
                }
            } else {
                //not negative
                left = l;
                right = i;
            }

            if (res < cnt2) {
                res = cnt2;
                delFront = left + 1, delBack = n - right;
            }
 
            l = i; //mark l with previous segment end

        }
    }
    cout << delFront << " " << delBack;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}
