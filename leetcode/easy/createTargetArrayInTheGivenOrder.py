class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for i in range(len(index)):
            target.insert(index[i], nums[i]) #insert nums[i] at index[i]
        return target

        #splicing
        # target = []
        # for i in range(len(index)):
        #     target = target[:index[i]] + [nums[i]] + target[index[i]:]
 #everything up to i (exclusive at i)  + insert nums[i] +. add the rest of target
        # return target
