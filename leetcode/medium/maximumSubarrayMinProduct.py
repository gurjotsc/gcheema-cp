class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        n = len(nums)
        
        pre = [0]
        for i in nums:
            pre.append(pre[-1] + i)
        
        def mono(res, loopRange, st = []):
            for i in loopRange:
                while st and nums[i] < nums[st[-1]]:
                    res[st.pop()] = i
                st.append(i)
        
        ple, nle = [-1]*n, [n]*n #prvious least element, next least element
        mono(ple, range(n-1, -1, -1))
        mono(nle, range(n))
        
        res = -inf
        for i in range(n):
            l, r = ple[i], nle[i] #store the ranges of the previous and next elements which are               smaller than i assuming i is the min
            s = pre[r]-pre[l+1] #r and l+1 because ple and nle are 0 indexed but pre is 1 indexed
            curr = nums[i] * s
            res = max(res, curr)
        
        return res % int(1e9+7)
            
            
            