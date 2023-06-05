from sortedcontainers import SortedList
class Solution:
    def findAndReplacePattern(self, words: List[str], p: str) -> List[str]:
        res = []
        n = len(p)
        def compare(w):
            nonlocal p
            d = dict()
            i = 0

            while(i < n):
                if p[i] in d:
                    if w[i] != d[p[i]]:
                        return False
                elif w[i] in d.values():
                    return False
                else:
                    d[p[i]] = w[i]
                i += 1
            
            return True

        for w in words:
            res += [w] if compare(w) else []

        return res