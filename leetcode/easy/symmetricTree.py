# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        l = root.left
        r = root.right
        return self.checkSymmetric(l,r)

    def checkSymmetric(self, l, r) -> bool:
        if(l == None and r == None): return True #leaf nodes' children are null
        if(l == None or r == None): return False #if one of them is null, but the other isn't
        #Note we check the and condition in the first line of the funciton so this assumes that          both won't evaluate to true
        if(l.val != r.val): return False ##if two mirror nodes don't have the same value
        #check to see if the subtrees of l and r are mirrored
        return (self.checkSymmetric(l.left, r.right) and self.checkSymmetric(l.right, r.left))
