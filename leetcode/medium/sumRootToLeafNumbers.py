# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        d = defaultdict(int)
        res = 0
        def dfs(r, s = ""):
            s += str(r.val)
            if not r.left and not r.right:
                d[int(s)] += 1
                return
            if r.left: dfs(r.left, s)
            if r.right: dfs(r.right, s)
        dfs(root)
        for path, cnt in d.items():
            res += (path * cnt)
        return res