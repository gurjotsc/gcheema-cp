class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        s = set([i[1] for i in paths])
        for i in paths: 
            if i[0] in s: s.remove(i[0])
        return next(iter(s))