# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        node_ret = None

        while head is not None:
            node = head
            head = head.next

            node.next = node_ret
            node_ret = node

        return node_ret
