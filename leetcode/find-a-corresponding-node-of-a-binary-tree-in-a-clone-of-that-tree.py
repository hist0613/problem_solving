# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, node1, node2, target):
        if node1 == target:
            self.answer = node2
            return
        if node1 is None:
            return
        self.dfs(node1.left, node2.left, target)
        self.dfs(node1.right, node2.right, target)
        
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        self.dfs(original, cloned, target)
        return self.answer
        