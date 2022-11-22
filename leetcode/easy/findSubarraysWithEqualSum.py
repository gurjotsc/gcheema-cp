class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        n = len(nums)
        d = defaultdict(int)
        for i in range(n-1):
            if nums[i] + nums[i+1] in d:
                return True
            else:
                d[nums[i] + nums[i+1]] += 1
        return False