class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res = []
        n = len(words)
        for i in range(n):
            for j in range(n):
                if i == j: continue
                if words[i] in words[j]:
                    res += [words[i]]
                    break
        return res