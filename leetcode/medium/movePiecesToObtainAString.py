class Solution:
    def canChange(self, start: str, target: str) -> bool:
        G = lambda c      : c != '_'
        O = lambda s,x    : [i for i, c in enumerate(s) if c == x]
        A = lambda t, comp: all(comp(x, y) for x,y in zip(O(start, t), O(target, t)))
        T = lambda        : [*filter(G, start)] == [*filter(G, target)]
        return T() and A('L', ge) and A('R', le)