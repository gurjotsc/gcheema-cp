class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        res = 0
        d = {}
        for i in answers:
            if i not in d or i == d[i]:
                d[i] = 0
                res += (i+1)
            else:
                d[i] += 1
        return res