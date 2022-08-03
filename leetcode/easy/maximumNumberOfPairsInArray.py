class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        res = [0, 0]
        c = Counter(nums)
        for i in c:
            res[0] += (c[i]//2)
            if c[i] % 2:
                res[1] += 1
        return res