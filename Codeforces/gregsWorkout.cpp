#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> muscle(3);
    for(auto& i : a) cin >> i;
    
    for(int i = 0; i < n; ++i) muscle[i%3] += a[i];

    if(muscle[0] > muscle[1] && muscle[0] > muscle[2]) cout << "chest";
    else if(muscle[1] > muscle[2]) cout << "biceps";
    else cout << "back";
    
}