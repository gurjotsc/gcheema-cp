class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        res, n = 0, len(properties)
        properties.sort(key = lambda x : (x[0], -x[1]))

        mx = properties[-1][1]
        for i in reversed(properties):
            if i[1] < mx:
                res += 1
            mx = max(mx, i[1])
                
        return res