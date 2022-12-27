class Solution:
    def __init__ (self):
        self.letters = defaultdict(tuple)
        def insert(x: int, y: tuple):
            self.letters[x] = y

        insert(2, ('a','b','c'))
        insert(3, ('d','e','f'))
        insert(4, ('g','h','i'))
        insert(5, ('j','k','l'))
        insert(6, ('m','n','o'))
        insert(7, ('p','q','r','s'))
        insert(8, ('t','u','v'))
        insert(9, ('w','x','y','z'))

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits: return []
        if len(digits) == 1: return list(self.letters[int(digits[0])])
        res = []
        
        for i in self.letters[int(digits[0])]:
            for j in self.letterCombinations(digits[1:]):
                res.append(i + j)

        return res