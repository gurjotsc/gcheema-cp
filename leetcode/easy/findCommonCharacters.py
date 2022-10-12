class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        c = Counter(words[0])
        for w in words[1:]:
            c2 = Counter(w)
            for k in c: c[k] = min(c[k], c2[k])
        return c.elements()