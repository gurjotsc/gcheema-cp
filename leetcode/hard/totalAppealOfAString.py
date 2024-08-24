class Solution:
    def appealSum(self, s: str) -> int:
        n = len(s)
        curr = res = 0
        last = [0] * 26
        for i, c in enumerate(s):
            curr += (i+1) - last[ord(c) - ord('a')]
            res += curr
            last[ord(c) - ord('a')] = i+1
        return res