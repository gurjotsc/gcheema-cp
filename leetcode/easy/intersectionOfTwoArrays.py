class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        s = {i for i in nums1} #store nums1 in a set
        #a set does not store duplicate values, so we only get one occurance of each i in nums1          in s
        for i in nums2:
            if i in s:
                res.append(i) #append it to res
                s.remove(i) # remove is from s so you only have unique values
        return res
        
