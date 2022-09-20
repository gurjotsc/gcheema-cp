class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        res, n = 0, len(s)
        for i in range(n-2):
            res += (len(set(s[i:i+3])) == 3)
        return res