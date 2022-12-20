class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [y for y,yy in sorted([(i,j) for i,j in zip(names, heights)], key = lambda x : x[1], reverse = True)]