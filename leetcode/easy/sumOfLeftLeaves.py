# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(r):
            nonlocal res
            if(not r):
                return
            if(r.left and not r.left.left and not r.left.right):
                res += r.left.val
            dfs(r.left)
            dfs(r.right)
        dfs(root)
        return res