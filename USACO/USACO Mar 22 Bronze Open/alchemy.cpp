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

vector<vector<int>> recipies;
vector<bool> useful;

void recurse(int make) {
    if(useful[make]) return;
    useful[make] = true;
    if(!recipies[make].size()) return;
    for(auto j : recipies[make]) recurse(j);

    // if(recipies.find(make) == recipies.end()) return;

    // auto& curr = recipies[make];
    // for(int i = 0; i < curr.size(); ++i) recurse(curr[i]);
    
    // int least = 1e6;
    // for(int i = 0; i < curr.size(); ++i) least = min(least, a[curr[i]-1]);
    // if(least) {
    //     for(int i = 0; i < curr.size(); ++i) a[curr[i]-1] -= least;
    //     a[make-1] += least;
    // }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, k; cin >> n;
    vector<int> a(n+1);
    recipies.resize(n+1);
    useful.resize(n+1);
    
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cin >> k;

    while(k--) {
        int l, m; cin >> l >> m;
        while(m--) {
            int curr; cin >> curr;
            recipies[l].push_back(curr);
        }
    }

    recurse(n);

    for(int i = 2; i <= n; ++i) {
        if(recipies[i].size() && useful[i]) {
            int least = 1e6;
            for(auto& j : recipies[i]) least = min(least, a[j]);
            for(auto& j : recipies[i]) a[j] -= least;
            a[i] += least;
        }
    }
    // for(int i = 0; i <= n; ++i) {
    //     cout << i << ": ";
    //     cout << recipies[i] << "\n";
    // }
    // cout << "useful: " << useful << "\n";
    // cout << a << "\n";

    cout << a[n];


}