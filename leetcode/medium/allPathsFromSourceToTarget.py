class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        res = []
        
        def dfs(i, path):
            if i == (n-1): res.append(path + [i])
            else:
                for j in graph[i]: dfs(j, path + [i])
        
        dfs(0, [])
        return res