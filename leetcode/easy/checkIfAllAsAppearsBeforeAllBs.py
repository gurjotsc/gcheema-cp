class Solution:
    def checkString(self, s: str) -> bool:
        return "ba" not in s
        #return ('b' not in s) or (not 'a' in s[s.index('b'):])