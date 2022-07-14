class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        res = []
        n = len(code)
        for i in range(n):
            if not k: res.append(0)
            elif k > 0:
                temp = k
                j = i+1
                res.append(0)
                while temp:
                    if j >= n: j = 0
                    res[i] += code[j]
                    j += 1
                    temp -= 1
            else:
                temp = abs(k)
                j = i-1
                res.append(0)
                while temp:
                    if j < 0: j = n-1
                    res[i] += code[j]
                    j -= 1
                    temp -= 1
        return res
                    