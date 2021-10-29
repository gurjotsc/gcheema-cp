class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        #keep track of how many chips are in even and odd slots
        evenCnt = 0
        oddCnt = 0
        #since it costs 0 to move 2 spaces, you can move all the evens to 0 and all the odds to 1          at no cost, then find whatever pile has less and move them all to the other pile for 1            cost each
        for i in position:
            if (not i%2):
                i = 0
                evenCnt += 1 #keep track of how many evens you moved
            else:
                i = 1
                oddCnt += 1 #keep track of how many odds you moved
        return min(evenCnt, oddCnt) #move the pile with least count to the othern at 1 cost per                                        chip
        
