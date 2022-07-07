class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        d = dict()
        d2 = dict()
        for i in s:
            if i in d: d[i] += 1
            else: d[i] = 1
        for i in target:
            if i in d2: d2[i] += 1
            else: d2[i] = 1
        
        mn = 1e18
        for i in target:
            if i not in d:
                return 0
            mn = min(mn, d[i]//d2[i])
        return mn