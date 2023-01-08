class Solution:
    def __init__(self):
        self.res = [0] * 20 #stores answer
        self.res[0] = self.res[1] = 1 #theres one way to format a tree with 0 or 1 nodes
        for i in range(2,20): #lets assume i is the root
            for j in range(1,i+1): #lets assume we have j on the left side
                self.res[i] += self.res[j-1] * self.res[i-j]

    def numTrees(self, n: int) -> int:
        return self.res[n]