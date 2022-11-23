class Solution:
    def combinationSum(self, c: List[int], target: int) -> List[List[int]]:
        n = len(c)
        c.sort()
        res = []
        
        def recurse(i, sm, p):
            nonlocal res
            if sm > target:
                return
            elif sm == target:
                res.append(p)
                return
            else:
                for j in range(i, n):
                    recurse(j, sm+c[j], p+[c[j]])
            
        for i in range(n):
            recurse(i, c[i], [c[i]])
        
        return res