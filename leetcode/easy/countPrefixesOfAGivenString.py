class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return len([1 for i in words if i in set([s[:x] for x in range(1,len(s)+1)])])