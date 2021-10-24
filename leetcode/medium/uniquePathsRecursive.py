class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #THIS WILL TLE
        if(m <= 0 or n <= 0): return 0 #Problem constraints are m and n are >= 1 (we index from                                         1 in this problem)
        if(m == 1 or n == 1): return 1 #In this case it is just a row or column with only one                                           way to get there (right if m = 1 or down if n = 1)
        #The number of ways to get to a square is just the number of way to get to the square            above and to the left of it
        return (self.uniquePaths(m-1, n) + self.uniquePaths(m, n-1))
