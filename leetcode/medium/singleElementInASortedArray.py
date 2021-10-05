class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        #declare hi and lo for binary search
        lo = 0
        hi = len(nums) - 1
        while(lo < hi):
            mid = lo + (hi - lo) // 2
            #if mid is even then its duplicate should be at mid + 1 if odd then its at mid - 1
            #We know this is true since the it starts off at index 0 and 1 being the same then 2 and 3 then 4 and 5 and so on. As soon as there is one to offset this we the two indexes won't match
            temp = mid + 1 if (not (mid % 2)) else mid - 1
            if(nums[mid] == nums[temp]): lo = mid + 1 #if the condition holds we know that the lone integer is above the mid index since the ordering of indexes 0-1, 2-3, 4-5, and so on is held on to at least until mid
            else: hi = mid #if not then we know it is either at mid or below it

        return nums[lo]
