class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        #sort it then return whatevers in the n/2 index
        #after sorting the number at the index will be the element that has occured at least n/2 times
        #The one with more than n/2 will always be the maximum since an answer always exists. Nothing after that index can be greater than n/2 and nothing before can be greater than n/2
        nums.sort()
        return nums[len(nums) // 2]
