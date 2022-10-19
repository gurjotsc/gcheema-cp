class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> f;
        for (auto& i : s) f[i]++;
        sort(s.begin(), s.end(), [&](auto a, auto b) {
            if (f[a] != f[b]) return f[a] >= f[b];
            else return a > b;
        });
        return s;
    }
};