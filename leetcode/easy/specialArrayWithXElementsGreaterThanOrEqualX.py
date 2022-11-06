class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort(reverse=True)
        lo, hi = 0, n
        while(lo < hi):
            mid = lo + ((hi-lo)//2)
            if(mid < nums[mid]):
                lo = mid+1
            else: hi = mid
        return -1 if lo < n and lo == nums[lo] else lo