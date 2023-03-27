class Solution {
public:
    set<int> s;
    Solution() {
        for(int i = 2; i <= 1000; ++i) s.insert(i);
        for(int i = 2; i <= 500; ++i) {
            int cnt = 2;
            while(i*cnt <= 1000) s.erase(i*cnt++);
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(nums[0] > 2) {
            auto temp = s.lower_bound(nums[0]);
            if(temp == end(s) || *temp >= nums[0]) temp = prev(temp);
            nums[0] -= *temp;
        }
        for(int i = 1; i < n; ++i) {
            if(nums[i] <= nums[i-1]) return false;
            auto it = s.lower_bound(nums[i] - nums[i-1] - 1);
            if(it == end(s) || *it > nums[i] || nums[i]-*it <= nums[i-1]) it = prev(it);
            if(nums[i]-*it <= nums[i-1]) continue;
            nums[i] -= *it;
        }
        return nums[n-1] > nums[n-2];
    }
};