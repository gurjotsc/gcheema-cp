class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        mn, mx, n = min(nums), max(nums), len(nums)
        #both store l deletions and r deletions for mn and mx
        mnDist, mxDist = [nums.index(mn)+1, n-nums.index(mn)], [nums.index(mx)+1, n-nums.index(mx)]
        lr = min(mnDist) + min(mxDist)
        l = max(mnDist[0], mxDist[0])
        r = max(mnDist[1], mxDist[1])
        return min([lr, l, r])