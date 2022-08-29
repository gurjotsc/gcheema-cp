class Solution:
    def minNumberOfHours(self, ie: int, x: int, e: List[int], ex: List[int]) -> int:
        res = max(0, (sum(e)-ie)+1)
        for i in ex:
            if x <= i:
                prev = res
                res += i - x + 1
                x += res-prev
            x += i
        return res