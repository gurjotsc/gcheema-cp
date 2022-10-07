class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d = dict()
        d2 = dict()
        for i in range(len(s)):
            if s[i] in d2:
                if d2[s[i]] != t[i]: return False
            elif t[i] in d:
                if d[t[i]] != s[i]: return False
            else:
                d[t[i]] = s[i]
                d2[s[i]] = t[i]
        return True