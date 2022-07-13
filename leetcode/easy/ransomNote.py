class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        d = dict()
        for i in magazine: 
            if i not in d: d[i] = 1
            else: d[i] += 1
        for i in ransomNote:
            if i not in d or not d[i]: return False
            d[i] -= 1
        return True