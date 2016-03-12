# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return

        temp_node = root.left
        root.left = root.right
        root.right = temp_node

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
