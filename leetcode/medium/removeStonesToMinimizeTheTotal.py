from sortedcontainers import SortedList
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        sl = SortedList(piles)
        for i in range(k): 
            val = sl[-1] - (sl[-1]//2)
            sl.remove(sl[-1])
            sl.add(val)
        return sum(sl)