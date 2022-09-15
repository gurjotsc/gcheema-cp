class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        n = len(s)
        res = bal = 0
        for i in range(n):
            if s[i] is '(': bal += 1
            else:
                bal -= 1
                res += 2**bal if s[i-1] == '(' else 0
        return res