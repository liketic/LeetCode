# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        # we can use a simple solution to solve this problem
        if root is None:
            return True

        lh = Solution.get_tree_height(root.left)
        rh = Solution.get_tree_height(root.right)

        return abs(lh - rh) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)

    @staticmethod
    def get_tree_height(root):
        if root is None:
            return 0
        return max(Solution.get_tree_height(root.left),
                   Solution.get_tree_height(root.right)) + 1
