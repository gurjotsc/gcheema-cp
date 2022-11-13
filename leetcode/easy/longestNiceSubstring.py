class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        i = j = 0
        n = len(s)
        res = ""
        
        def check(a):
            ss = set(a)
            for c in ss:
                if c.swapcase() not in ss:
                    return False
            return True
            
        for i in range(n):
            for j in range(i+1, n):
                if check(s[i:j+1]):
                    res = s[i:j+1] if len(s[i:j+1]) > len(res) else res
        return res