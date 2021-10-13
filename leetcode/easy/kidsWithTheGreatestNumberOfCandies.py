class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        n = len(candies)
        m = 0
        res = []
        #find the kid with the most candies. Store amount in m
        for i in candies: m = max(m, i)
        #if the ith kid has equal to or more candies than m when given extraCandies, then append True else append False
        for i in candies:
            if(i + extraCandies >= m): res.append(True)
            else: res.append(False)
        return res
