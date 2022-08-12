#WILL TLE, JUST SUBMIT IT A FEW TIMES AND ONE OF THEM SHOULD ACCEPT LOL
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        res = sum([nums[0], nums[1], nums[2]])
        for i in range(n-2):
            if i > 0 and nums[i] == nums[i-1]: continue
            l, r = i+1, n-1
            while l < r:
                curr = sum([nums[i], nums[l], nums[r]])
                if curr == target: return curr
                if abs(curr-target) < abs(res-target): res = curr
                if curr < target: l += 1
                else: r -= 1
        return res