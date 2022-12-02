class Solution:
    def minSteps(self, s: str, t: str) -> int:
        res = 0
        ss, tt, = Counter(s), Counter(t)
        for i in ss:
            res += max(0, ss[i]-tt[i])
        for i in tt:
            res += max(0, tt[i]-ss[i])
        return res