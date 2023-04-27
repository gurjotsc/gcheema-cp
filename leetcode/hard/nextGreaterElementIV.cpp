class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<int> nxt(n);
        stack<pair<int, int>> st;

        for(int i = 0; i < n; ++i) {
            while(!st.empty() && nums[i] > st.top().first) {
                nxt[st.top().second] = i;
                st.pop();
            }
            st.push({nums[i], i});
        }

        while(!st.empty()) {
            nxt[st.top().second] = -1;
            st.pop();
        }
        
        vector<vector<pair<int, int>>> v(n);
        multiset<pair<int, int>> ms;
        for(int i = 0; i < n; ++i) {
            if(nxt[i] > -1) v[nxt[i]].push_back({nums[i], i});
            
            auto it = begin(ms);
            while(it != end(ms) && nums[i] > (*it).first) {
                res[(*it).second] = nums[i];
                ++it;
                ms.erase(prev(it));
            }

            for(auto x : v[i]) ms.insert(x);
        }

        return res;
    }
};