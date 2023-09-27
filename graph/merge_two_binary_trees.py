# 1617. Merge Two Binary Trees


# You are given two binary trees root1 and root2.

# Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

# Return the merged tree.

# Note: The merging process must start from the root nodes of both trees.


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def merge_trees(root1, root2):
    """
    :type root1: TreeNode
    :type root2: TreeNode
    :rtype: TreeNode
    """

    if root1 and root2:
        left = merge_trees(root1.left, root2.left)
        right = merge_trees(root1.right, root2.right)

        return TreeNode(root1.val + root2.val, left, right)
    else:
        return root1 or root2


root1 = TreeNode(1, TreeNode(3, TreeNode(5)), TreeNode(2))
root2 = TreeNode(2, TreeNode(1, None, TreeNode(4)), TreeNode(3, None, TreeNode(7)))
merged = merge_trees(root1, root2)
assert merged.val == 3
assert merged.left.val == 4
assert merged.right.val == 5
assert merged.left.left.val == 5
assert merged.left.right.val == 4
assert merged.right.left is None
assert merged.right.right.val == 7


root1 = TreeNode(1)
root2 = TreeNode(1, TreeNode(2))
merged = merge_trees(root1, root2)
assert merged.val == 2
assert merged.left.val == 2
assert merged.right is None

print("All tests passed!")
