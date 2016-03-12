# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None

        p = head.next
        q = head

        while p is not None:
            if p.val == q.val:
                p = p.next
                q.next = p
            else:
                q = q.next
                p = p.next

        return head
