#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int numConnectedComponenets = 0;
void dfs(vector<int>& xCoords, vector<int>& yCoords, int i) {
    xCoords[i] = 0;
    yCoords[i] = 0;
    for(int j = 0; j < n; ++j) {
        if(!xCoords[j]) continue;
        if(xCoords[j] == xCoords[i] || yCoords[j] == yCoords[i])
            dfs(xCoords, yCoords, j);
    }
}
int main() {
    cin >> n;
    vector<int> xCoords(n);
    vector<int> yCoords(n);
    for(int i = 0; i < n; ++i) {
        cin >> xCoords[i];
        cin >> yCoords[i];
    }
    for(int i = 0; i < n; ++i) {
        if(!xCoords[i]) continue;
        dfs(xCoords, yCoords, i);
        ++numConnectedComponenets;
    }
    cout << numConnectedComponenets - 1;
}
