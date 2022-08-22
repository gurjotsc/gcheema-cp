from functools import lru_cache

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        s = set(days)
        durs = [1, 7, 30]

        @lru_cache(None)
        def dp(i):
            if i > 365:
                return 0
            elif i in s:
                return min(dp(i+d)+c for c, d in zip(costs, durs))
            else:
                return dp(i+1)

        return dp(1)