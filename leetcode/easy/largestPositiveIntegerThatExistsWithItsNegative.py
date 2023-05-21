class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        st = set([i for i in nums if i < 0])
        res = max([i for i in nums if i > 0 and -i in st] + [-1])
        return res