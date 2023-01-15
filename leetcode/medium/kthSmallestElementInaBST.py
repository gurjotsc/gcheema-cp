# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        kCnt = res = 0

        def dfs(r):
            nonlocal kCnt, res
            if not r:
                return
            dfs(r.left)
            kCnt += 1
            if kCnt == k:
                res = r.val
            dfs(r.right)
        
        dfs(root)
        return res