# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        answer = 0
        node = head
        while node:
            answer = answer * 2 + node.val
            node = node.next
        return answer