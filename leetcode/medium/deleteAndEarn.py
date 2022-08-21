class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        n = len(nums)
        scores = [0]*(int(1e5)+1)
        for i in nums:
            scores[i] += i

        take = 0
        skip = 0
        for i in scores:
            takei = skip + i
            skipi = max(skip, take)
            take = takei
            skip = skipi

        return max(take, skip)
