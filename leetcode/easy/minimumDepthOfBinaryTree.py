# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        if root.left == None or root.right == None:
            #you want the max because this assumes that one of the paths goes down further and the other has nothing                (so not a leaf node)
            #when there are no children you'll just return 0 for both
            return max(self.minDepth(root.left), self.minDepth(root.right)) + 1
        else:
            #has two children
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1