class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        res = 0
        x = lambda a : a[1]
        boxTypes.sort(key=x)
        print(boxTypes)
        for i in reversed(boxTypes):
            if truckSize <= 0: break
            res += (i[0]*i[1]) if (truckSize - i[0]) >= 0 else (truckSize * i[1])
            truckSize -= i[0]
        return res