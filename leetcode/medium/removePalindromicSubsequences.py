class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return len(s) if len(s) <= 1 else (1 if s[::-1] == s else 2)