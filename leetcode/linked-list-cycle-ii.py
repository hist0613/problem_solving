# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        visit = set()
        node = head
        while node:
            if node in visit:
                return node
            visit.add(node)
            node = node.next
        return None