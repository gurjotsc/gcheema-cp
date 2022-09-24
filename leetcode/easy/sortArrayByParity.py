class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        return list(filter(lambda x: not x%2, nums)) + list(filter(lambda x: x%2, nums))