class Solution:
    def largestInteger(self, num: int) -> int:
        num = str(num)
        num = list(num)
        e = []
        o = []
        for i in num:
            if (ord(i)-ord('0')) % 2:
                o.append(i)
            else:
                e.append(i)
        e.sort(reverse = True)
        o.sort(reverse = True)
        num = [o.pop(0) if (ord(i)-ord('0')) % 2 else e.pop(0) for i in num]
        num = ''.join(num)
        return int(num)
        