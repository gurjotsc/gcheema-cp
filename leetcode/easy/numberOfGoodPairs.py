class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        res = 0;
        m = {}
        #iterate through nums (note this algorithm is only one pass)
        for i in nums:
            if i in m:
                res += m[i] #increment res by how many i's have occured PREVIOUSLY
                m[i] += 1 #increment m[i]
                '''
                Although the problem asks for i < j, we can solve this problem backward
                Since you know how many times an i has occured, you can make pairs between how                   many i's have occured previously and the current i
                This will give us the same number of pairs since now the condition is just i > j
                We only increment after updating res so we don't count the current pair in our                   pairs because we can't make a pair with ourself (i cannot == j)
                '''
            else: m[i] = 1 #else add it to the map
        return res
