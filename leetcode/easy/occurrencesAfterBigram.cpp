class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        int n = text.size(), i = 0;
        vector<string> res;
        istringstream ss(text);
        string pprev, prev, word;
        while(ss >> word) {
            if(pprev == first && prev == second) res.push_back(word);
            pprev = prev; prev = word;
        }
        return res;
    }
};