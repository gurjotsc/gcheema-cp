class Solution:
    def getHint(self, s: str, g: str) -> str:
        n = len(s)
        bulls = cows = 0
        sc = Counter(s)
        b = set()
        for i in range(n):
            if g[i] == s[i]:
                bulls += 1
                b.add(i)
                sc[g[i]] -= 1

        for i in range(n):
            if i not in b:
                if sc[g[i]]:
                    sc[g[i]] -= 1
                    cows += 1
        
        return str(bulls)+"A"+str(cows)+"B"