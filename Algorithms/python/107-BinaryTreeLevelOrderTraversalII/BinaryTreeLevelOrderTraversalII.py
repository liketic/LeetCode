# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        level_list = list()

        if root is None:
            return level_list

        node_q = list()
        node_q.append(root)
        node_size = 1

        while node_size > 0:

            current_list = list()

            for i in range(node_size):
                node = node_q.pop(0)
                current_list.append(node.val)

                if node.left is not None:
                    node_q.append(node.left)
                if node.right is not None:
                    node_q.append(node.right)
            level_list.append(current_list)
            node_size = len(node_q)

        level_list.reverse()
        return level_list


