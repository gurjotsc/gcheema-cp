class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1);
        int currIdx = 0;
        //note* for deque, the item on the front is the oldest and the item on the back is the youngest
        deque<int> q;
        
        for(int i = 0; i < n; ++i) {
            //pop anything thats not in the window
            while(!q.empty() && q.front() < i-k+1) q.pop_front();
            //pop anything thats less than nums[i]
            //If there is a number in the q that is >= nums[i], anything after thats smaller will get popped
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            //if !the first window. Aka start filling res when i = first window and after
            if(i >= k-1) res[currIdx++] = nums[q.front()];
        }
        
        
        return res;
    }
};
