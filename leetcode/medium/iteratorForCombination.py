class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.ch = characters
        self.cl = combinationLength
        self.l = set()

        def recurse(i: int, st: str = ""):
            if len(st) == combinationLength:
                    self.l.add(st)
                    return
            for j in range(i, len(characters)):
                recurse(j+1, st+characters[j])
        recurse(0)
        self.l = sorted(list(self.l))
        self.n, self.i = len(self.l), 0

    def next(self) -> str:
        self.i += 1
        return self.l[self.i-1]

    def hasNext(self) -> bool:
        return self.i < self.n


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()