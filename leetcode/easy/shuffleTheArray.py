class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = []
        #iterate through both parts of the array and push them in ans
        for i,j in zip(nums[:n], nums[n:]):
            ans += [i,j]
        return ans
