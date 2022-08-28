class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        if ch not in word: return word
        return (''.join([i for i in reversed(word[:word.index(ch)+1])])) + word[word.index(ch)+1:]