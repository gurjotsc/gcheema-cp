from collections import defaultdict
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        x = defaultdict()
        y = defaultdict()
        res = []
        n1, n2 = len(nums1), len(nums2)
        for i in range(n2):
            x[i] = -1
            y[nums2[i]] = i
            for j in range(i+1, n2):
                if nums2[j] > nums2[i]:
                    x[i] = j
                    break
        print(y, x)
        for i in nums1:
            if i in y:
                if x[y[i]] != -1:
                    res.append(nums2[x[y[i]]])
                    continue
            res.append(-1)
        return res
                