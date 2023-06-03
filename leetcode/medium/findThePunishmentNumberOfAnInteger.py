class Solution:
    def punishmentNumber(self, n: int) -> int:
        res = 0
        flag = False

        def check(prev, s, i, sm) -> bool:
            nonlocal flag
            if(not s):
                if(prev):
                    sm += int(prev)
                if(sm == i):
                    flag = True
                return
            
            if(sm > i):
                return
            
            prev += s[0]
            check("", s[1:], i, sm+int(prev))
            check(prev, s[1:], i, sm)

        for i in range(1, n+1):
            check("", str(i**2), i, 0)
            res += (i**2) if flag else 0
            flag = False

        return res