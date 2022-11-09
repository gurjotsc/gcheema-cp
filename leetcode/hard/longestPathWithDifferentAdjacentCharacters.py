class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        n = len(s)
        children = [[] for _ in range(n)]
        for i,j in enumerate(parent):
            if j >= 0:
                children[j].append(i)
        res = 0
        def dfs(i):
            nonlocal res
            largest = secondLargest = 0
            for j in children[i]:
                curr = dfs(j)
                if s[i] == s[j]: continue
                if(curr > largest):
                    secondLargest = largest
                    largest = curr
                elif(curr > secondLargest):
                    secondLargest = curr
            
            res = max(res, largest+secondLargest+1)
            return largest+1
        dfs(0)
        return res
        