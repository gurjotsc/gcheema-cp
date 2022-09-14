class Solution:
    def removeStars(self, s: str) -> str:
        stack = []
        for i in s:
            if i is not '*': stack.append(i)
            else: stack.pop()
        return ''.join(stack)