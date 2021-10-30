class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        m = 0 #max
        res = 0
        ##look through the list
        for i in rectangles:
            #when you find a new max length update the length and restart your res
            if (m is not max(m, min(i))):
                res = 1
                m = min(i)
            #if its not a new max length, then if the min length of rectangle i is the same as                maxlengh then you can increment your res
            else:
                if (min(i) == m): res += 1
        return res
