class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res, prevGroup, currGroup = 0, 0, 1
        n = len(s)
        for i in range(1, n):
            if s[i-1] != s[i]:
                res += min(prevGroup, currGroup)
                prevGroup, currGroup = currGroup, 1
            else: currGroup += 1
        return res + min(prevGroup, currGroup)