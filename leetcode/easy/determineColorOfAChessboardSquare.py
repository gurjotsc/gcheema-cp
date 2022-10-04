class Solution:
    def squareIsWhite(self, c: str) -> bool:
        if(ord(c[0]) - ord('a')) % 2: 
            if not (ord(c[1]) - ord('1')) % 2:
                return True
            else: return False
        else: 
            if (ord(c[1]) - ord('1')) % 2: return True
            else: return False