class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 1) return 0;
        unordered_map <char, int> m;
        for (auto& c : s) {
            m[c]++; //stores each character once but increments the int everytime it sees it.
            //In leetcode since l and d only appear once, m['l'] and m['d'] are one but m['e'] is three
        }
        for(int i = 0; i < s.size(); ++i) {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
};
