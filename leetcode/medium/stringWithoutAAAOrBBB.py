class Solution:
    def strWithout3a3b(self, ੳ: int, ਅ: int) -> str:
        res = []
        #a is 1 b is 0
        while ੳ or ਅ:
            if len(res) >= 2 and res[-1] == res[-2]: choice = (res[-1] == 'b')
            else: choice = (ੳ >= ਅ)
            if choice:
                ੳ -= 1
                res.append('a')
            else:
                ਅ -= 1
                res.append('b')
        return ''.join(res)