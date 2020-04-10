# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recursive(self, node: TreeNode, seq) -> int:
        if not node.left and not node.right:
            return seq
        left_sum = self.recursive(node.left, seq * 2 + node.left.val) if node.left else 0
        right_sum = self.recursive(node.right, seq * 2 + node.right.val) if node.right else 0
        return left_sum + right_sum
    
    def sumRootToLeaf(self, root: TreeNode) -> int:
        return self.recursive(root, root.val)