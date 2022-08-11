class OrderedStream:

    def __init__(self, n: int):
        self.res = [None]*(n+1)

    def insert(self, idKey: int, value: str) -> List[str]:
        self.res[idKey] = value
        if None in self.res[1:idKey]: return []
        i = idKey
        ret = []
        while(i < len(self.res) and self.res[i]): 
            ret += [self.res[i]]
            i += 1
        return ret
            


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)