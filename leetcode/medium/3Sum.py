import bisect
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = set()
        s = set()
        s.add(nums[0])
        for j in range(1,n): 
            for k in range(j+1, n):
                sm = (nums[j] + nums[k])
                if -(sm) in s:
                    res.add(tuple(sorted([-(nums[j] + nums[k]), nums[j], nums[k]])))
            s.add(nums[j])
        return list(res)



        # n = len(nums)
        # res = set()
        # nums.sort()
        # l, r = 0, n-1
        # while l < r:
        #     curr = nums[l] + nums[r]
        #     i = bisect.bisect_left(nums, -curr, l+1, r-1) 
        #     if i < n:
        #         if ((nums[i] == -curr and i != l and i != r) or (nums[i-1] == -curr and i-1 != l and i-1 != r)):
        #             res.add(tuple(sorted([-curr, nums[l], nums[r]])))
        #     r -= 1
        #     if r <= l:
        #         l += 1
        #         r = n-1
            
        # return list(res)