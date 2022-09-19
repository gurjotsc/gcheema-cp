class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        dp = [0] * n # how many before are less than j
        res = 0
        for j in range(1,n):
            for i in range(j): dp[j] += (rating[i] < rating[j])
        for k in range(n):
            for j in range(k):
                if rating[k] > rating[j]: res += dp[j]
        #same backwards
        dp = [0] * n
        for j in range(n-1,-1,-1):
            for k in range(j+1,n): dp[j] += (rating[j] > rating[k])
        for i in range(n-1,-1,-1):
            for j in range(i+1,n):
                if rating[i] > rating[j]: res += dp[j]
        return res