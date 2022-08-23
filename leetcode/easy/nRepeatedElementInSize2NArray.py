class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        return list(Counter(nums).keys())[list(Counter(nums).values()).index(len(nums)//2)]
