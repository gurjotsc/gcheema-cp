#include <bits/stdc++.h>
using namespace std;
using ll = long long;
                     
int main() {
    int t; cin >> t;
    vector<int> nums;
    int i = 1;
    while(nums.size() < 1000){
        if(i % 3 && i % 10 != 3) {
            nums.push_back(i);
        }
        ++i;
    }
    while(t--) {
        int k; cin >> k;
        cout << nums[k-1] << endl;
    }
}