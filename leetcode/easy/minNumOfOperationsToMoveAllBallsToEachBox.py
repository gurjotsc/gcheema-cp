class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        # you know that for each index, you have the cost of moving the balls on the left
        # plus the cost of moving balls on the right of it
        # If we can compute these for each index, we can add the two together to get the
        # solution for each index
        # the costs can be found by seeing how many 1's are on the left and right and
        # incrementing by how many we have on the left and rights we loop through
        n = len(boxes)
        ans = [0] * n
        leftCount, leftCost, rightCount, rightCost = 0, 0, 0, 0
        for i in range(1, n):
            if boxes[i-1] == '1': leftCount += 1 #if the previous character is one, increment                                                     the count of the left by one
            leftCost += leftCount # since the for loop is incremented by one, the leftCost will                                     increase by leftCount since that is how many 1's to the left                                     need to move one more space for the ith index
            ans[i] = leftCost #leftCost + rightCost but we will update this below
        #repeat the same process backwards for right count
        for i in range(n-2, -1, -1): #-1 not included in range so it stops at 0
            if boxes[i+1] == '1': rightCount += 1
            rightCost += rightCount
            ans[i] += rightCost

        return ans
