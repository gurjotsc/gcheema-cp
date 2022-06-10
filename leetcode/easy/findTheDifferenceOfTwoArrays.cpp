class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        vector<vector<int>> res(2);
        for(auto i : nums1) s1.insert(i);
        for(auto i : nums2) s2.insert(i);
        for(auto i : s1) 
            if(!s2.count(i)) res[0].push_back(i);
        for(auto i : s2) 
            if(!s1.count(i)) res[1].push_back(i);
        return res;
    }
};