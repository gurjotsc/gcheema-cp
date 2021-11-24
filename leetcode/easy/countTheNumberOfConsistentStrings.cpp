class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> a (begin(allowed), end(allowed));
        int ans = words.size();
        for(int i = 0; i < words.size(); ++i) {
            for (auto c : words[i]) {
                if(a.find(c) == a.end()) {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};
