class SmallestInfiniteSet:

    def __init__(self):
        self.small = 1
        self.i = 1
        self.s = set()

    def popSmallest(self) -> int:
        if len(self.s) and self.small > min(self.s):
            mn = min(self.s)
            self.small = mn
            self.s.remove(mn)
            temp = copy.deepcopy(self.small)
            self.small = self.i
            return temp
        temp = copy.deepcopy(self.small)
        self.i += 1
        self.small = self.i
        return temp
        

    def addBack(self, num: int) -> None:
        if num >= self.i: return
        self.s.add(num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)