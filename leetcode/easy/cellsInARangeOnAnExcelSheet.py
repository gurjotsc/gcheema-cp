class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        res = []
        for c in range(ord(s[0]), ord(s[3])+1):
            for r in range(ord(s[1]), ord(s[4])+1):
                res.append(chr(c)+chr(r))
        return res