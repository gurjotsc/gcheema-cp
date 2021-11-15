class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        //update frequnecies
        for(auto i : word1) ++m1[i];
        for(auto i : word2) ++m2[i];

        //compare frequencies
        for(auto i : m1) if (m2[i.first] > i.second + 3 || m2[i.first] < i.second - 3) return false;
        for(auto i : m2) if (m1[i.first] > i.second + 3 || m1[i.first] < i.second - 3) return false;

        return true;
    }
};
