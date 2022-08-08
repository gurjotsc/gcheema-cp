class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        n = len(nums)
        dpe = [0]*n
        dpo = [0]*n
        res = 0
        for i in range(n):
            if i%2:
                dpo[i] = dpo[i-1]+nums[i]
                dpe[i] = dpe[i-1]
            else:
                dpe[i] = dpe[i-1]+nums[i]
                dpo[i] = dpo[i-1]

        for i in range(n):
            e = dpe[i]
            o = dpo[i]

            if i%2: o -= nums[i]
            else: e -= nums[i]
                
            o += dpe[-1]-dpe[i]
            e += dpo[-1]-dpo[i]
            
            res += (e==o)

        return res