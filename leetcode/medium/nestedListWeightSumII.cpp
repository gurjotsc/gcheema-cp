/*
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();


 maxDepth - (the depth of the integer) + 1
}
/*


class Solution {
public:
    }
    int findWeightedSum(vector<NestedInteger>& nest) {
      int max = 0;
     for (int i = 0; i < nest.size(); i++) {
        if(max < getDepth(nest[i]), 1);
            max = getDepth(nest[i], 1);
     }

     int j = 0;
     int sum = 0;
     while (j < nest.size()) {
        j++;
        sum += getSum(nest[ij, 1, max);
     }
     return sum;
    }

    int getSum(vector<NestedInteger>& nest, int depth, int max) {
      for (int i = 0; i < nest.size(); i++) {
         if(nest[i].isInteger()) {
            return nest[i].getInteger() * max - depth + 1;
         }
         else {
            depth++;
            return getSum(nest[i], depth) * max - depth + 1;
         }
      }
   }

   int getDepth(vector<NestedInteger>& nest, int depth) {
      for (int i = 0; i < nest.size(); i++) {
         if(nest[i].isInteger()) {
            return depth;
         }
         else {
            depth++;
            return getDepth(nest[i], depth) * depth;
         }
      }
   }
};
