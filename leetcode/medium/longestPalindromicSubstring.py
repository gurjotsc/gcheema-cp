class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        res = [0,0]
        
        def expandFromCenter(l: int, r: int) -> list:
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            return [l+1, r-1]
        
        for i in range(n):
            s1 = expandFromCenter(i,i)
            s2 = expandFromCenter(i,i+1)
            if s1[1]-s1[0] > res[1]-res[0]: res = s1
            if s2[1]-s2[0] > res[1]-res[0]: res = s2

        return s[res[0]:res[1]+1]