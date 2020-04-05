# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traverse(self, node, is_left=False):
        # is_leave True
        if not node:
            return 0
        if not node.left and not node.right:
            return node.val if is_left else 0
        
        left_sum = self.traverse(node.left, is_left=True)
        right_sum = self.traverse(node.right, is_left=False)
        
        return left_sum + right_sum
               
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return self.traverse(root, is_left=False)