class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        #since you know that each number appears twice except for the result,
        #a number XORed with itself is 0
        #say nums is [2, 2, 3, 1, 3]
        #Associatve law statez i1^i2^i3^...i(n-1) == i1^i7^i(n-1)^...iwhatever
        #in other words, if the operation is the same, order doesn't matter
        #hence, since each number appears twice, xoring them with each other is always 0
        #eventually 0 xor with result is just result
        for i in nums:
            res ^= i
        return res
