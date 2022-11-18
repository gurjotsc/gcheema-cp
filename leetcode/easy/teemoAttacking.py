class Solution:
    def findPoisonedDuration(self, ts: List[int], dur: int) -> int:
        res, st, end = 0, ts[0], ts[0]+dur-1
        for t in ts[1:]:
            if t > end:
                res += (end-st+1)
                st = t
            
            end = t+dur-1
            # print(res, st, end)
        res += (end-st+1)
        return res