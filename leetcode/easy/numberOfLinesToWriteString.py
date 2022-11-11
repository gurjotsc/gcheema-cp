class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        res = [0, 0]
        n = len(s)
        i = sm = 0
        while(i < n):
            if(widths[ord(s[i])-ord('a')]+sm > 100):
                res[0] += 1
                sm = widths[ord(s[i]) - ord('a')]
            else:
                sm += widths[ord(s[i]) - ord('a')]
            i += 1
        res[1] = sm
        res[0] += 1
        return res