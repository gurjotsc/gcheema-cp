class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def isSelfDividing(n:int) -> bool:
            nStr = str(n)
            for i in nStr:
                if i is '0': return False
                elif n % (ord(i)-ord('0')): return False
            return True
        return list(filter(isSelfDividing, range(left, right+1)))