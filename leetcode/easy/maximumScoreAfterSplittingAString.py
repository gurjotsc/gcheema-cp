class Solution:
    def maxScore(self, s: str) -> int:
        ones = s.count('1') - (s[0] == '1')
        zeroes = (s[0] == '0')
        res = 0
        for i in range(1, len(s)):
            res = max(res, ones+zeroes)
            ones -= (s[i] == '1')
            zeroes += (s[i] == '0')
        return res