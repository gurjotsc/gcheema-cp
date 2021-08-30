class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter;
        unordered_map<int, int> m;
        for(int i = 0; i < nums1.size(); ++i) {
            if(m.find(nums1[i]) == m.end()) {
                m[nums1[i]] = 1;
            }
            else ++m[nums1[i]];
        }
        for(int j = 0; j < nums2.size(); ++j) {
            if(m.find(nums2[j]) != m.end()) {
                if(m[nums2[j]] < 1) {
                    continue;
                }
                inter.push_back(nums2[j]);
                --m[nums2[j]];
            }
        }
        return inter;
    }
};
