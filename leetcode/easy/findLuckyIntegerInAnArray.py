class Solution:
    def findLucky(self, arr: List[int]) -> int:
        return max([i if Counter(arr)[i] == i else -1 for i in Counter(arr)])