class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #dp is going to store the number of ways to get to square (m,n)
        #first store everything with ones
            #we do this because for just the first row and column there is only one way to get                there (a strinht line down or to the right)
        dp = [[1 for _ in range(n)] for _ in range(m)]
        #iterate through the grid
        for i in range(1,m):
            for j in range(1,n):
                #the only way to enter a square is to either enter from th left or above
                #thus
                #dp[i][j] = number of ways to get to the one to the left + above
                dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[-1][-1] #-1 access the last element
