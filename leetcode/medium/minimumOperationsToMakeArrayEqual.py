class Solution:
    def minOperations(self, n: int) -> int:
        return (n//2)*((n//2)+1) if n%2 else ((n//2)*((n//2)+1))-(n//2)