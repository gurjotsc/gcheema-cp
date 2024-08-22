class Solution:
    def strangePrinter(self, s: str) -> int:
        i = 1
        while i < len(s):
            if s[i] == s[i-1]:
                s = s[:i] + s[i+1:]
            i += 1
        
        n = res = len(s)
        memo = [[-1 for _ in range(n)] for _ in range(n)]

        def minimum_turns(start: int, end: int) -> int:
            if start > end:
                return 0
            if memo[start][end] != -1:
                return memo[start][end]
            
            mn_turns = 1 + minimum_turns(start + 1, end)
            for i in range(start + 1, end + 1): #end plus one becasue you want end to be included
                if s[i] == s[start]:
                    turns_with_match = minimum_turns(start, i-1) + minimum_turns(i+1, end)
                    mn_turns = min(mn_turns, turns_with_match)
            
            memo[start][end] = mn_turns
            return mn_turns

        return minimum_turns(0, n-1)