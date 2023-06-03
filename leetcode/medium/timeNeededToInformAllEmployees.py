class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        if (n == 1):
            return informTime[0]

        children = [[] for _ in range(n)]
        res = 0
        for i in range(len(manager)):
            if i == headID:
                continue
            else:
                children[manager[i]] += [i]

        def dfs(p, curr):
            nonlocal children, informTime, res

            if(not len(children[p])):
                res = max(res, curr)
                return

            for c in children[p]:
                dfs(c, curr+informTime[p])
        
        dfs(headID, 0)
        return res