#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

//Output templates for vector, pair, (unordered) map, (unordered) set. Input for vectors
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



int solve() {
    string s; cin >> s;
    int n = s.size();
    map<char, int> m;
    vector<pii> v;
    int res = n;
    for(int i = 0; i < n; ++i) {
        if(m.count(s[i])) v.push_back({m[s[i]], i});
        m[s[i]] = i;
    }
    if(!v.size()) return n;

    //Key point
    //v will already be ordered by endpoint. Only after the first interval is closed will it get pushed back into v. 
    //This means the smallest right bounds will be pushed back first and we can then chose intervals greedily since the smallest right bound you take will open up the most intervals later in the vector

    int currRightBound = v[0].second;
    int intervalsTaken = 1;
    for(int i = 1; i < v.size(); ++i) {
        if(v[i].first > currRightBound) {
            currRightBound = v[i].second;
            intervalsTaken++;
        }
    }

    //lets first start off assuming we delete every letter. 
    //Hence we start with n
    //From this, we can subtract how many characters we will keep at the end
    //Each interval is a pair of characters, so multiply by 2 for 2 characters
    return n - (2*intervalsTaken);


}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}
