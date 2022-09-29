class Solution:
    def sortSentence(self, s: str) -> str:
        n = len(s)
        cnt, w = 0, ""
        for i in s: cnt += (i == ' ')
        res = [None] * (cnt+1)
        
        for i in s:
            if i == ' ': continue
            if i >= '1' and i <= '9':
                res[int(i)-1] = w
                w = ""
            else: w += i
        return ' '.join(res)