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

bool comp(pair<ll, ll> a, pair<ll, ll> b) {return a.second < b.second;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> colors(n, vector<ll>(m));
    unordered_map<ll, vector<pair<ll, ll>>> idxs;
    ll res = 0ll;

    for(ll i = 0ll; i < n; ++i) {
        for(ll j = 0ll; j < m; ++j) {
            cin >> colors[i][j];
            idxs[colors[i][j]].push_back({i,j});
        }
    }

    for(auto it = idxs.begin(); it != idxs.end(); ++it) {
        auto& curr = it->second;
        sort(curr.begin(), curr.end());
        ll currSum = 0ll;
        for(auto& x : curr) currSum += x.first;
        for(ll i = 0ll; i < curr.size(); ++i) {
            // for(ll j = i + 1; j < curr.size(); ++j) {
            //     res += ((curr[j].first - curr[i].first) + (curr[j].second - curr[i].second));
            // }
            currSum -= curr[i].first;
            res += (currSum - ((curr.size()-1-i)*(curr[i].first)));
        }

        sort(curr.begin(), curr.end(), comp);
        currSum = 0ll;
        for(auto& x : curr) currSum += x.second;
        for(ll i = 0ll; i < curr.size(); ++i) {
            // for(ll j = i + 1; j < curr.size(); ++j) {
            //     res += ((curr[j].first - curr[i].first) + (curr[j].second - curr[i].second));
            // }
            currSum -= curr[i].second;
            res += (currSum - ((curr.size()-1-i)*(curr[i].second)));
        }
    }

    cout << res;
}