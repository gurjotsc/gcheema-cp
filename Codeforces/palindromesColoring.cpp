#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;


int solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> freq(26);
    int res;
    for(auto& c : s) ++freq[c-'a'];

    int numPairs = 0, numOdd = 0;
    for(auto& i : freq) {
        if(i%2) ++numOdd;
        numPairs += (i/2);
    }
    //the number of pairs that need to fit into each k colors * 2 (the length of a pair)
    //i.e if you have 4 pairs (2 sets of characters, say, aabbaabb) then you can safley increase the length of the smallest palindorme
    res = (numPairs/k) * 2;
    //Number of additional characters you could add
    numOdd += (numPairs%k) * 2;

    //if numOdd >= k then you have enough charcters to add a character to the middle of a palindrome for EACH numPairs
    //it would increaase the length of the samllest palindrome by 1 also
    if(numOdd >= k) ++res;

    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
}