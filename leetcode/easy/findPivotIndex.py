class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        s = sum(nums) #total sum O(n)
        lSum = 0 #stores the sum to the left of the pivot
        for i in range(len(nums)):
            #if you know how much the lSum is then the rSum is just the
            #total sum (s) - the sum to the left (lSum) - nums[i] (since we don't include the                  pivot in the comparison)
            rSum = s - nums[i] - lSum
            #if the two are the same then the condition is met
            if(lSum == rSum): return i
            #update lSum after the return because we will use it for the next iteration
            lSum += nums[i]
        return -1
            
