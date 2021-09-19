#include <bits/stdc++.h>
using namespace std;

int main() {
    int numTestCase; cin >> numTestCase;
    long long ans = 0;
    for(int i = 0; i < numTestCase; ++i) {
        int numHouses; cin >> numHouses;
        string temp; cin >> temp;
        stack<int> s;
        vector<int> forward(numHouses);
        vector<int> backward(numHouses);

        for(int j = numHouses - 1; j >= 0; --j) {
            if(temp[j] == '1') {
                backward[j] = -1;
                int x = j;
                while(!s.empty()) {
                    backward[++x] = j;
                    s.pop();
                }
                continue;
            }
            s.push(0);
        }
        int j = -1;
        while(!s.empty()) {
            s.pop();
            backward[++j] = -1;
        }

        for(int j = 0; j < numHouses; ++j) {
            if(temp[j] == '1') {
                forward[j] = -1;
                int x = j;
                while(!s.empty()) {
                    forward[--x] = j;
                    s.pop();
                }
                continue;
            }
            s.push(0);
        }

        j = numHouses;
        while(!s.empty()) {
            s.pop();
            forward[--j] = -1;
        }
        for(int i = 0; i < numHouses; ++i) {
            if(temp[i] == '1') continue;
            int back = abs(backward[i] - i);
            int forth = abs(forward[i] - i);
            if(backward[i] == -1) ans += forth;
            else if(forward[i] == -1) ans += back;
            else ans += min(back, forth);
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
