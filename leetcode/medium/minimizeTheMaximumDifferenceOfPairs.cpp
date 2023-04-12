class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int lo = 0, hi = nums[n-1]-nums[0];
        while(lo < hi) { //O(log(max(nums)))
          int mid = lo+((hi-lo)/2);
          int cnt = 0;
          for(int i = 0; i < n-1 && cnt < p; ++i) { //O(p) == O(n/2) == O(n)
            if(nums[i+1]-nums[i] <= mid) {
              ++i;
              ++cnt;
            }
          }
          if(cnt == p) hi = mid;
          else lo = mid+1;
        }
        return lo;
    }
};