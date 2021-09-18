class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        ans = 0

        #Create a map that maps each ratio to an int
        count = defaultdict(int)

        #For each pair, increment that ratio by one, but only after increaseing ans
        #The reason we do it after increasing ans, is because we don't want to count the first one (since it isn't interchangeable with anything)
        #Each time we have a new ratio inputted, we can create that many more pairs (essentially we are just adding another pair to each of the previous pairs for that key)
        for w, h in rectangles:
            g = gcd(w, h) #Use the greatest common divisor as a way to reduce the ratio
            key = ((w//g), (h//g)) #Store this ratio
            ans += count[key]
            count[key] += 1

        return ans
