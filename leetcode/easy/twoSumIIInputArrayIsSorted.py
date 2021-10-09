class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        nums = dict()
        for i in range(len(numbers)):
            difference = target - numbers[i] #for each index see what you need for target
            if difference in nums: #if you've seen what you need before, you canr edturn that                                       (indexed by 1)
                return [nums[difference] + 1, i + 1]
            else: nums[numbers[i]] = i #you haven't seen this number so add it to the map
