class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if(not n):
            return 1
        
        res = 10
        uniqueDigits = 9
        availableNums = 9

        while(n > 1 and availableNums > 0):
            uniqueDigits *= availableNums
            res += uniqueDigits
            n -= 1
            availableNums -= 1

        return res