# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return None
        if root.val == val:
            return root
        
        left = self.searchBST(root.left, val)
        right = self.searchBST(root.right, val)
        
        if left: return left 
        elif right: return right
        else: return None