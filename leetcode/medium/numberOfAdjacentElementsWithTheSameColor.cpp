class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int curr = 0;
        vector<int> nums(n);
        vector<int> res;
        for(auto q : queries) {
            int prev = nums[q[0]];
            nums[q[0]] = q[1];

            if(q[0] < n-1 && prev) curr -= (prev == nums[q[0]+1]);
            if(q[0] > 0 && prev) curr -= (prev == nums[q[0]-1]);
            if(q[0] < n-1) curr += (nums[q[0]] == nums[q[0]+1]);
            if(q[0] > 0) curr += (nums[q[0]] == nums[q[0]-1]);

            res.push_back(curr);
        }
        return res;
    }
};