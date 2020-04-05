# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

INT_MIN = -987654321
INT_MAX = 987654321
class Solution:
    def maxSumBST(self, root):
        self.answer = 0
        
        # return min, max, sum
        def dfs(node):
            if not node:
                return INT_MAX, INT_MIN, 0
            
            left_min, left_max, left_sum = dfs(node.left)
            right_min, right_max, right_sum = dfs(node.right)
            if left_max < node.val and node.val < right_min:
                this_sum = node.val + left_sum + right_sum
                self.answer = max(self.answer, this_sum)
                return min(node.val, left_min), max(node.val, right_max), this_sum
            else:
                return INT_MIN, INT_MAX, 0
        
        dfs(root)
        
        return self.answer