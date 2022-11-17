"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        res = 1
        if not root:
            return 0
        def dfs(r, lvl):
            nonlocal res
            if not r.children:
                res = max(res, lvl)
            for i in r.children:
                dfs(i, lvl+1)
        
        dfs(root, 1)
        return res