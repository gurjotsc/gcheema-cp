class Solution {
public:
    int next(vector<int>& nums, int i) {
        return (nums.size() + nums[i] + i) % nums.size();
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int &num: nums)
            num %= n;
        for(int i=0;i<n;i++){
            int slow = i,
                fast = i;
            while(nums[slow]*nums[next(nums,fast)]>0 && nums[slow]*nums[next(nums,next(nums,fast))]>0){
                slow = next(nums,slow);
                fast = next(nums,next(nums,fast));
                if(slow==fast){
                    if(slow==next(nums,slow))
                        return false;
                    return true;
                }
            }
            int j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int nexx = next(nums,j);
                nums[j] = 0;
                j = nexx;
            }
        }

        return false;
    }
};
