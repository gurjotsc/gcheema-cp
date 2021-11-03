class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        ans = []
        #let this be the maximum number possible
        #*note this number is just 11111... maximumbit times
        maxNum = 2**maximumBit - 1
        temp = nums[0] #start temp here
        #if you take any number, xor it with all ones, you will just get the not of that number
        #in other words you will get the opposite of that number (flip the bits)
        #i.e 110100 ^ 111111 = 001011
        #xoring the origonal number with your answer, again gives you all ones
        #i.e 110100 ^ 001011 = 111111
        ans.append(temp ^ maxNum)
        #The problem states that nums[i] <= 2^maximumBit - 1 so we won't ever have to worry about          having too many bits which lets us compute the following
        for i in range(1, len(nums)):
            temp ^= nums[i] #continually xor temp
            #find the xor with the maxNum and you will get a k that maximizes the answer
            ans.append(temp ^ maxNum)
        return reversed(ans) #reverse it since we xor forward
