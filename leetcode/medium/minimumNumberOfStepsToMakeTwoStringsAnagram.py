class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cs, ct = Counter(s), Counter(t)
        res = 0
        for i in cs:
            if cs[i] > ct[i]:
                res += (cs[i]-ct[i])
        return res