class Solution:
    def reinitializePermutation(self, n: int) -> int:
        perm = [i for i in range(n)]
        arr = [perm[i//2] if not (i%2) else perm[((n//2)+((i-1)//2))] for i in range(n)]
        res = 1
        while arr != perm:
            arr = [arr[i//2] if not (i%2) else arr[((n//2)+((i-1)//2))] for i in range(n)]
            res += 1
        return res