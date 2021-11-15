#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main() {
    // freopen("stacking.in", "r", stdin);
    // freopen("stacking.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> stacks(n+1);
    vector<int> prefix(n);

    //store the increment stacks at the start of each range and decrement when the range is done
    //This will allow you to indicate that everything in between stacks a and b (the instruction range given by FJ)
    //be incremented by 1 so that prefix sum can iterate through it in O(n)
    for(int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        ++stacks[a-1];
        --stacks[b];
    }
    //*note stacks[n] is never accessed
    //this is because it will only ever be <=0 meaning it will decrement that stack (which doesn't exist becasue we are zero-indexed)
    // and the following stacks (which again don't exist)
    //for this reason we set the size of prefix to n because we don't need to represent anything with prefix[n]
    prefix[0] = stacks[0];
    for(int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + stacks[i];
    }

    sort(prefix.begin(), prefix.end()); //sort to return the median
    cout << prefix[n/2] << "\n";


}
