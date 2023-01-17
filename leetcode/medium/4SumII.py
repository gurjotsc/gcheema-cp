class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        n = len(nums1)
        res = 0
        d = defaultdict(int)

        for i in nums1:
            for j in nums2:
                d[i+j] += 1

        for i in nums3:
            for j in nums4:
                res += d[-(i+j)]

        return resa