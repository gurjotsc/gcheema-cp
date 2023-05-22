class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        n = len(s)
        res = list(s)
        l, r = 0, n-1

        while(l < r):
            if s[l] != s[r]:
                if(ord(s[l]) < ord(s[r])):
                    res[r] = res[l]
                else:
                    res[l] = res[r]
            
            l += 1
            r -= 1
        
        return ''.join(res)
