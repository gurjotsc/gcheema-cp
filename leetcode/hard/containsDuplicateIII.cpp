class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < indexDiff; ++i) 
            m[nums[i]] += 1;
        for(int i = 0; i < n; ++i) {
            m[nums[i]] -= 1;
            if(!m[nums[i]]) m.erase(nums[i]);

            if (i+indexDiff < n)
                m[nums[i+indexDiff]] += 1;
            if(i-indexDiff > 0) {
                m[nums[i-indexDiff-1]] -= 1;
                if(!m[nums[i-indexDiff-1]]) m.erase(nums[i-indexDiff-1]);
            }
            
            if(m.upper_bound(nums[i]) != end(m) && m.upper_bound(nums[i])->first <= nums[i]+valueDiff)
                return true;
            if(m.lower_bound(nums[i]-valueDiff) != end(m) && m.lower_bound(nums[i]-valueDiff)->first-valueDiff <= nums[i])
                return true;
            
            m[nums[i]] += 1;
        }

        return false;
    }
};