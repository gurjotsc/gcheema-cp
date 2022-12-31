class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        cnt = 0 #stores the number of changes made. There should be n changes
        start = 0 #the index we start updating from
        while cnt < n:
            curr = start
            prev = nums[curr]
            while True:
                nxt = (curr+k)%n
                temp = nums[nxt]
                nums[nxt] = prev
                prev = temp
                curr = nxt
                cnt += 1
                
                if start == curr:
                    break
            start += 1