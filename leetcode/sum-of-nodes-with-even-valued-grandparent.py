# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node):
        try:
            if node.parent.parent.val % 2 == 0:
                self.answer += node.val
        except AttributeError:
            pass
        
        if node.left:
            node.left.parent = node
            self.dfs(node.left)
        if node.right:
            node.right.parent = node
            self.dfs(node.right)
        
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        self.answer = 0
        root.parent = None
        
        self.dfs(root)
        return self.answer
        