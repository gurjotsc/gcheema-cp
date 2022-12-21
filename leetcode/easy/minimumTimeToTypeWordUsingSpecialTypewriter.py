class Solution:
    def minTimeToType(self, word: str) -> int:
        n = len(word)
        res = 0
        curr = 'a'
        for target in word:
            if target > curr:
                res += min(ord(target)-ord(curr), (ord('z')-ord(target)+1) + (ord(curr)-ord('a')))+1
            else:
                res += min(ord(curr)-ord(target), (ord('z')-ord(curr)+1) + (ord(target)-ord('a')))+1
            curr = target
        return res