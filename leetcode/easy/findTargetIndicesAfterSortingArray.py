class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        return [i for i in range(len(nums)) if sorted(nums)[i] == target]