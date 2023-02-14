class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        int m = bw.size();
        unordered_set<string> seen;
        unordered_set<string> words(begin(wl), end(wl));

        queue<pair<string, int>> q;
        q.push({bw, 1});

        while(!q.empty()) {
            auto [curr, lvl] = q.front(); q.pop();
            if (curr == ew) return lvl;
            for(int i = 0; i < m; ++i) {
                string temp = curr;
                for(char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if(words.count(temp) && !seen.count(temp)) {
                        q.push({temp, lvl+1});
                        seen.insert(temp);
                    }
                }
            }
        }
        
        return 0;
    }
};