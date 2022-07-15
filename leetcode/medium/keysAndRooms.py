class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [0 for _ in rooms]
        def dfs(curr):
            for i in rooms[curr]:
                if visited[i]: continue
                visited[i] = 1
                dfs(i)
        visited[0] = 1
        dfs(0)
        return 0 not in visited