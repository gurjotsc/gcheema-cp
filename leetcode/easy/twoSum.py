class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = dict()
        for i in range(len(nums)):
            d[nums[i]] = i #store everything in a dict
        for i in range(len(nums)):
            temp = target-nums[i] #what number we need for the given index
            if temp in d:
                if d[temp] is not i: return [i, d[temp]] #return what index it is stored at, if it exists
