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





int res = 0;

struct Node {
    int val;
    vector<Node*> children;
};


void dfs(Node* root) {
    if(!root->children.size()) return;
    int mn = -1;
    for(int i = 0; i < root->children.size(); ++i) {
        dfs(root->children[i]);
        if(mn == -1) mn = root->children[i]->val;
        else mn = min(mn, root->children[i]->val);
        res += root->children[i]->val;
    }
    root->val = max(root->val, mn);
    res -= mn;
}


int solve() {
    int n; cin >> n;
    vector<int> f(n+1); 
    for(int i = 1; i <= n; ++i) cin >> f[i];
    vector<pii> p(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> p[i].first;
        p[i].second = i;
    }

    
    vector<Node*> nodes(n+1);
    Node* root = new Node;
    root->val = 0;
    nodes[0] = root;

    for(int i = 1; i <= n; ++i) {
        Node* curr = new Node;
        curr->val = f[p[i].second];
        nodes[p[i].first]->children.push_back(curr);
        nodes[p[i].second] = curr;
    }
    
    dfs(root);
    return res+root->val;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int t; cin >> t;
    int cnt = 1;
    while (t--) {
        cout << "Case #" << cnt++ << ": " << solve() << "\n";
        res = 0;
    }
}



// 1
// 11
// 20 50 30 40 17 16 1 2 1 2 3
// 0 1 1 1 3 3 4 4 6 6 6