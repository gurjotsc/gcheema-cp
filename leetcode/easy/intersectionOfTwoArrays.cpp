class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s;
        for(int i : nums1) s.insert(i); //store all of nums1 in a set
        for(int i : nums2) {
            if(s.find(i) != s.end()){ //if i in nums2 is in nums1
                res.push_back(i); //push_back i
                s.erase(s.find(i)); //remove it from the set
            }
        }
        return res;
    }
};
