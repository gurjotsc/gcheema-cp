class Solution:
    def countPairs(self, nums: List[int]) -> int:
        def permutations(a: str) -> set:
            a = list(a)
            res = set([int(''.join(a))])
            for i in range(len(a)):
                for j in range(i+1, len(a)):
                    a[i], a[j] = a[j], a[i]
                    res.add(int(''.join(a)))
                    a[i], a[j] = a[j], a[i]
            return res

        
        n, res = len(nums), 0
        l = [permutations(str(x)) for x in nums]
        for i in range(n):
            for j in range(i+1, n):
                if (l[i] & {nums[j]}) or (l[j] & {nums[i]}):
                    res += 1
        
        return res