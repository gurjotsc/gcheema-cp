class Solution:
    def canBeTypedWords(self, t: str, bl: str) -> int:
        return len([1 for i in t.split(' ') if len([1 for c in i if c not in bl]) == len(i)])