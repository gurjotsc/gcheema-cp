class Solution:
    def minimumDeletions(self, s: str) -> int:
        res = numB = 0
        for i in s:
            res = min(res+1, numB) if i is 'a' else res
            numB += (i == 'b')
        return res