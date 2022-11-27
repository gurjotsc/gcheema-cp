class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        l = list(zip(mat, [i for i in range(n)]))
        l.sort(key=lambda x : sum(x[0]))
        return [l[i][1] for i in range(k)]