class Solution:
    def minPartitions(self, n: str) -> int:
        ans = 0
        #since you can only increment each placeholder by 1, the max digit is your answer.
        for i in n:
            if (int(i) == 9): return int(i)
            ans = max(ans, int(i))
        return ans
