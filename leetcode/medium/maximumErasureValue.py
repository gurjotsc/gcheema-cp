class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        pre = [nums[0]]
        for i in nums[1:]:
            pre += [pre[-1] + i]
        l = 0
        d = defaultdict(int)
        sm = 0
        # print(pre)
        for r, val in enumerate(nums):
            if val in d:
                l = max(l,d[val]+1)
            sm = (pre[r] - pre[l-1]) if l != 0 else pre[r]
            d[val] = r
            res = max(res, sm)
        return res