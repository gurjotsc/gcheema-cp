class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(auto i : intervals) {
            if(!res.size()) res.push_back(i);
            else {
                if(i[0] <= res[res.size()-1][1])
                    res[res.size()-1][1] = max(res[res.size()-1][1], i[1]);
                else res.push_back(i);
            }
        }
        return res;
    }
};