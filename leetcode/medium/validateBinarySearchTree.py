# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, r: Optional[TreeNode], mn: int = -(2**31)-1, mx: int = (2**31)) -> bool:
        if not r:
            return True

        if r.val <= mn or r.val >= mx:
            return False

        return self.isValidBST(r.left, mn, r.val) and self.isValidBST(r.right, r.val, mx)