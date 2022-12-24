class Solution:
    def minSwaps(self, s: str) -> int:
        s = list(s)
        n = len(s)
        balance = res = 0
        r = n-1
        for l in range(n):
            balance += 1 if s[l] == '[' else -1

            if balance < 0:
                while l < r and s[r] is not '[':
                    r -= 1
                
                s[l], s[r] = s[r], s[l]
                res += 1
                balance = 1
        return res