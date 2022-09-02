class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        res = 0
        p = [2,3,5,7,11,13,17,19,23,29,31]
        for i in range(left, right+1):
            res += bin(i).count('1') in p
        return res