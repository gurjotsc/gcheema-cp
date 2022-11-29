# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def height(r):
            return -1 if not r else 1+height(r.left)
        
        h = height(root)
        
        if h < 0:
            return 0
        if height(root.right) == h-1:
            return (1 << h) + self.countNodes(root.right)
        else:
            return (1 << h-1) + self.countNodes(root.left)