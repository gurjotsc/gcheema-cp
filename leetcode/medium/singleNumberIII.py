class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        
        for i in nums:
            xor ^= i
        
        setBit = bin(xor)[2:][::-1].index('1')
        one = 0
        zero = 0

        for i in nums:
            if (1 << setBit) & i: one ^= i
            else: zero ^= i

        return [one, zero]