class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        res = 0
        track = 0
        for i in gain:
            track += i
            res = max(res, track)
        return res