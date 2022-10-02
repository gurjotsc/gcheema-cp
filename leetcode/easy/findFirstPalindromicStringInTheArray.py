class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        def isPalindrome(w : str) -> bool: return w[::-1] == w
        for w in words: 
            if isPalindrome(w): return w
        return ""