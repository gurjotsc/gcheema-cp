class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        n = len(triplets)
        res = [0,0,0]
        x,y,z = target
        for a,b,c in triplets:
            if(a <= x and b <= y and c <= z):
                res = [max(res[0],a), max(res[1],b), max(res[2],c)]
        return res == target