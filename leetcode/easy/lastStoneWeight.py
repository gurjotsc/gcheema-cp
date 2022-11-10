from sortedcontainers import SortedList
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        sl = SortedList()
        for i in stones: 
            sl.add(i)
        while(len(sl) > 1):
            x, y = sl[-2], sl[-1]
            if(x < y):
                sl.add(y-x)
                sl.remove(x)
                sl.remove(y)
            else:
                sl.remove(x)
                sl.remove(y)
        return 0 if not len(sl) else sl[0]