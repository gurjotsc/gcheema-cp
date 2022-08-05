class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()
        while(n != 1):
            sm = 0
            for i in str(n): sm += (int(i) ** 2)
            if sm in s: return False
            n = sm
            s.add(n)
        return True