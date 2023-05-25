class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        g = [set() for _ in range(n)]
        adj = [[] for _ in range(n)]
        res = 0

        for c in connections:
            g[c[0]].add(c[1])
            adj[c[0]] += [c[1]]
            adj[c[1]] += [c[0]]
        
        def dfs(r, p):
            nonlocal res
            for c in adj[r]:
                if c != p:
                    temp = res
                    res += (r not in g[c])
                    dfs(c, r)
        
        dfs(0, -1)
        
        return res