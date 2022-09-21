class Solution:
    def __init__(self):
        self.dp = [0] * 31
        self.dp[0], self.dp[1] = 0, 1
        for i in range(2,31): self.dp[i] = self.dp[i-1] + self.dp[i-2]
    
    def fib(self, n: int) -> int:
        return self.dp[n]