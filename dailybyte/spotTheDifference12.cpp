//Switching from py to cpp starting here to get more experience.
#include <bits/stdc++.h>

using namespace std;

char spotTheDifference(string s, string t);

int main() {
    string s = "coding"; string t = "ingcod";
    cout << endl << spotTheDifference(s, t) << endl << endl;
    return 0;
}

char spotTheDifference(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) return '\0'; //Return empty char

    for(int i = 0; i < t.size(); ++i) {
        if(i == t.size() - 1) return t[i];
        if(t[i] != s[i]) return t[i];
    }

    return 'E'; //return an error, although the problem states this case won't happen
}
