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
    vector<int> a(n); cin >> a;
    unordered_map<int, int> m;
    //map<int, vector<int>> m;
    int res = -1;

    //the max harmonious string will have the second substring extend all the way down to the end of the string, since you could always just extend the left substring without changing the idx
    for(int i = 0; i < n; ++i) {
        if(!m.count(a[i])) {
            m[a[i]] = i;
            continue;
        }
        else {
            //(n-end) - give you number of nums after the r bound
            //"     " + start = the max length of the string
            //Think about it like this
            //The maximum you can extend the right string is (n-end)
            //You can of course extend the left string ot the right by the same amount wihout effecting the idx of the repeat
            //but how much to the left should you go?
            //All the way to the left
            //This is ok because we can start the right substring anywhere before r.
            //Thus, if we start the left substring always at the beginning and extend it to the right by however many the right substring can extend by (n-end) you will achieve the maximum length of a harmonious substring for that a[i]
            //i.e 4 5 1 3 2 1 6 7 8
            //                | | | : (n-end)
            //    4 5 1 3 2 1 6 7 8
            //    | | |             : start
            //    4 5 1 3 2 1 6 7 8
            //l - | | | | | |
            //    4 5 1 3 2 1 6 7 8
            //r -       | | | | | |
            int start = m[a[i]], end = i;
            res = max(res, n-end+start);
            m[a[i]] = i;
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