class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        //dp[i] = do the numbers set in bin(i) satisfy the target condition so far?
        vector<bool> dp(pow(2,n));
        vector<int> total(pow(2,n), 0); //stores the sum of the set bits in bin(i)
        int sm = accumulate(begin(nums), end(nums), 0); //total sum
        int target = sm/k; //target sum for each subset
        dp[0] = true;
        
        sort(begin(nums), end(nums));
        if(sm%k) return false; //can't divide the total sum into k subsets
        if(nums[n-1] > target) return false; //the greatest number is too big to fit in any subset

        //i is going to represent the indicies you've "chosen" for this iteration
        for(int i = 0; i < (1<<n); ++i){
            if(!dp[i]) continue; //its confirmed that dp[i] is not possible
            for(int j = 0; j < n; ++j) {
                int temp = i | (1 << j); //lets add the jth index to our ith solution
                if(temp == i) continue; //you didn't add a new number
                
                //here rem represents the number we're trying to sum to
                //so everytime rem reaches 0, you can imagine that we've simulated completing one of the k subsets in our solution
                int rem = target - (total[i]%target);
                if(nums[j] <= rem) {
                    dp[temp] = true; //its still valid to include nums[j] in the ith solution
                    total[temp] = total[i] + nums[j]; //we take the sum of the iteration i and add it with the nums[j]
                }
                else break; //since the array is sorted, we know that the following numbers [j...n-1] are gonna be greater than rem
            }
        }
        return dp[(1<<n)-1];
    }
};