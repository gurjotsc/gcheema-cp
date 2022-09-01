# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, r, targetSum, s):
        if r.left and r.right: return self.dfs(r.left, targetSum, s+r.val) or self.dfs(r.right, targetSum, s+r.val)
        elif r.left: return self.dfs(r.left, targetSum, s+r.val)
        elif r.right: return self.dfs(r.right, targetSum, s+r.val)
        else: return s+r.val == targetSum
        
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root: return False
        return self.dfs(root, targetSum, 0)