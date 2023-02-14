class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        set<pair<int, string>> s;
        map<int, set<string>> mm;
        for(auto w : words) {
            if(m.count(w)) {
                int cnt = m[w];
                ++m[w];
                s.erase({cnt, w});
                s.insert({cnt+1, w});
            }
            else {
                m[w] = 1;
                s.insert({1, w});
            }
        }
        for(auto it = prev(end(s)); it != prev(begin(s)); --it)
            mm[it->first].insert(it->second);

        for(auto it = rbegin(mm); it != rend(mm) && res.size() != k; ++it)
            for(auto it2 = begin(it->second); it2 != end(it->second) && res.size() != k; ++it2)
                res.push_back(*it2);
        return res;
    }
};