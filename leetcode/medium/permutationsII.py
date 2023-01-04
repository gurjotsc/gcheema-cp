class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = set()
        n = len(nums)

        def permutations(i: int, ll: list = [None]*n):
            if not (None in ll):
                res.add(tuple(ll))
                return

            for j in range(n):
                if ll[j] == None:
                    ll[j] = nums[i]
                    permutations(i+1, ll)
                    ll[j] = None
        
        permutations(0)
        return list(res)