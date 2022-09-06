class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        n = len(pref)
        res = 0
        for w in words:
            if len(w) < n: continue
            res += (w[:n] == pref)
        return res