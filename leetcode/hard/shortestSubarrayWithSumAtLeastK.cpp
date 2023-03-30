class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n+1;
        vector<long long> p(n+1);
        for(int i = 0; i < n; ++i) p[i+1] = nums[i]+p[i];
        
        deque<int> dq; //monotnic increasing queue. Can't use priority queue because _____________

        for(int j = 0; j <= n; ++j) {
            while(!dq.empty() && p[j] <= p[dq.back()])
                dq.pop_back();
            while(!dq.empty() && p[j] >= p[dq.front()]+k) {
                res = min(res, j-dq.front());
                dq.pop_front();
            }
            dq.push_back(j);
        }
        return res == n+1 ? -1 : res;
    }
};