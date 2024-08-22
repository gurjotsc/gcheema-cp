# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(r: Optional[TreeNode], prev) -> int:
            nonlocal res
            if not r:
                return 0
            

            length = 0
            longest_path_left = longest_path_right = 0

            longest_path_left = dfs(r.left, r.val)
            longest_path_right = dfs(r.right, r.val)

            # if not p.right and not p.left and p.val == 5:
            #     print(length, longest_path_left, longest_path_right)
            
            if r.left and r.left.val == r.val:
                length += longest_path_left
            if r.right and r.right.val == r.val:
                length += longest_path_right
            
            res = max(res, length)

            return max(longest_path_left, longest_path_right) + 1 if r.val == prev else 0
        
        
        dfs(root, -1)
        return res