class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def f(w): return int(
            ''.join([chr(ord('0')+ord(i)-ord('a')) for i in w]))
        return f(firstWord) + f(secondWord) == f(targetWord)
