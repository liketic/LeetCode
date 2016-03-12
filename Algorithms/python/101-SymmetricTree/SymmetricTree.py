# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # empty tree treated ok
        return root is None or self.is_symmetric(root.left, root.right)

    def is_symmetric(self, p, q):
        """
        :param p: first tree
        :param q: second tree
        :return: if p and q is symmetric
        """
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        return p.val == q.val and self.is_symmetric(p.left, q.right) and self.is_symmetric(p.right, q.left)
