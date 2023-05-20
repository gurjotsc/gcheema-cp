class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        for i in nums:
            tmp = []
            while(i):
                tmp = [i%10]+tmp
                i //= 10
            res += tmp
        return res