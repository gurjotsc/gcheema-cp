class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        d = dict(items1)
        print(d)
        for i in items2:
            try:
                d[i[0]] += i[1]
            except KeyError:
                d[i[0]] = i[1]
            # if i[0] in d:
            #     d[i[0]] += i[1]
            # else: 
            #     d[i[0]] = i[1]
        return sorted([[key, value] for key,value in d.items()])