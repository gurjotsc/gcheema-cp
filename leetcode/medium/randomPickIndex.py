class Solution:

    def __init__(self, nums: List[int]):
        self.nums, self.n = nums, len(nums);
        lst = lambda:list()
        self.d = defaultdict(lst)
        for i in range(self.n): self.d[self.nums[i]].append(i)

    def pick(self, target: int) -> int:
        return random.choice(self.d[target])


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)