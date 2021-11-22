#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    //sorting Solution
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> nums;

    for(int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    int ans = 1;
    for(int i = 1; i < n; ++i) {
        if(nums[i] != nums[i-1]) ++ans;
    }

    cout << ans;
    //set solution
        // cin.tie(0);
        // ios::sync_with_stdio(false);
        //
        // int n; cin >> n;
        // set<int> seen;
        // int ans = 0;
        // while(n--) {
        //     int temp; cin >> temp;
        //     if(seen.find(temp) == seen.end()) {
        //         ++ans;
        //         seen.insert(temp);
        //     }
        // }
        //
        // cout << ans;
}
