#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

template<typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
    for (auto& item : data) {
        input >> item;
    }
    return input;
}


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> res(n+1, -1);
    vector<int> freq(n+1);

    for(auto& i : a) {
        cin >> i;
        ++freq[i];
    }

    sort(a.begin(), a.end());
    
    stack<int> s;
    //stores the number of operations to get to the first mex
    //The next mex that you need to solve for will require you getting the previous mex and then solving for how many operations will it take you to change the number ////in the stack to make the current one the mex (i.e take )
    ll sum = 0ll; 
    for(int i = 0; i <= n; ++i) {
        if(i > 0 && !freq[i-1]) {
            //you have no more numbers left to change then break
            //all future numbers(mexs) will require the past i to be in the array. This means that after we pop, we need to see what else is available in the stack. If there is nothing available (even if we had numbers in their in the past that were popped to allow for previous mexes) then break because you have no numbers to update
            //If there is nothing in the stack, then you can output -1 for all future i's since you don't have any numbers left in the stack to make i a mex
            if(s.empty()) break; 

            auto temp = s.top(); s.pop();
            sum += i - temp - 1;
        }

        res[i] = sum + freq[i];

        if(!i) continue;
        while(freq[i-1] > 1) {
            --freq[i-1];
            s.push(i-1);
        }
    }

    for(auto& i : res) cout << i << " ";
    
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}