class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        vector<pair<int, int>> del;
        for(int i = 0; i < n; ++i) {
            m[i] = nums[i];
            if(i < n-1 && nums[i] > nums[i+1]) del.emplace_back(i, i+1);
        }
        int res = 0;
        while(!del.empty()) {
            ++res;
            vector<pair<int, int>> nxt;
            for(auto& [i, j] : del) m.erase(j);
            for(auto& [i, j] : del) {
                if(!m.count(i)) continue; //this i was also a j that got deleted
                auto it = m.find(i);
                if(prev(m.end()) == it) continue; //if it is the last element
                auto itn = next(it);
                if(it->second > itn->second) nxt.emplace_back(it->first, itn->first); //store all indicies of what elements you need to delete next
            }
            swap(nxt, del);
        }
        return res;
    }
};