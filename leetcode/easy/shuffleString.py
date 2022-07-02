class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        n = len(s)
        res = [None]*n
        for i in range(n):
            res[indices[i]] = s[i]
        return ''.join(res)