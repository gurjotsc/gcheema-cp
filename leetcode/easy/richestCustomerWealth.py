class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans = 0
        #iterate through accounts and see if the sum is greater than the previous max
        for i in accounts:
            s = sum(i)
            ans = max(ans, s)
        return ans
                
