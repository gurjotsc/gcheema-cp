class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> d(deadends.begin(), deadends.end());
        unordered_set<string> seen;
        queue<string> q;
        q.push("0000");
        int res = 0;
        while(!q.empty()) {
            vector<string> hold;
            while(!q.empty()) {
                string curr = q.front(); q.pop();
                if(curr == target) return res;
                if(seen.count(curr) || d.count(curr)) continue;
                else seen.insert(curr);
                
                for(int i = 0; i < 4; ++i) {
                    string temp = curr;
                    if(temp[i] == '9') {
                        temp[i] = '0'; hold.push_back(temp);
                        temp[i] = '8'; hold.push_back(temp);
                    }
                    else if(temp[i] == '0') {
                        temp[i] = '9'; hold.push_back(temp);
                        temp[i] = '1'; hold.push_back(temp);
                    }
                    else {
                        temp[i]++; hold.push_back(temp);
                        temp[i]-=2; hold.push_back(temp);
                    }
                }
            }
            ++res;
            //there is no path to target without getting stuck
            //in this case nothing can be pushed to hold because all paths that lead to it are in deadends
            if(!hold.size()) return -1;
            for(auto& i : hold) q.push(i);
        }
        
        return res;
    }
};