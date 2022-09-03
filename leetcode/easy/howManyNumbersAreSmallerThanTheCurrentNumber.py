class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        res = copy.deepcopy(nums)
        nums.sort()
        for i in range(len(res)): res[i] = nums.index(res[i])
        return res