class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr, res = 0, -inf
        #Kadane's Algo
        for i in nums:
            curr = max(i, curr + i) #reset curr everytime curr is negative (because you are not helping the sum of the subarray)
            res = max(res, curr)
        return res