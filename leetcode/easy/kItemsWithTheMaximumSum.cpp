class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return min(k, numOnes) + ((min(k-numOnes-numZeros, numNegOnes) <= 0) ? 0 : min(k-numOnes-numZeros, numNegOnes)*-1);
    }
};