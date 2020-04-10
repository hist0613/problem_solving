# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        ans = 0
        buffer = [root]
        while len(buffer) > 0:
            ans = sum([node.val for node in buffer])
            new_buffer = []
            for node in buffer:
                if node.left: new_buffer.append(node.left)
                if node.right: new_buffer.append(node.right)
            buffer = new_buffer
            
        return ans