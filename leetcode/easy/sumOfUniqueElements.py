class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        d = set()
        seen = set()
        for i in nums:
            if i in d:
                d.remove(i)
            elif i not in seen:
                d.add(i)
            seen.add(i)
        return sum(d)
                
                