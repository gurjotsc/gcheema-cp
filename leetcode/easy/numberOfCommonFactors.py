class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        return sum([(not (a%i) and not(b%i)) for i in range(1,min(a,b)+1)])