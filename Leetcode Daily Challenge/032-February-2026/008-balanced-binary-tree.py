# https://leetcode.com/problems/balanced-binary-tree/




# Definition for a binary tree node.
# class TreeNode:
def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
    def height(self, root):
        if not root:
            return 0

        L = self.height(root.left)
        if L == -1:
            return -1

        R = self.height(root.right)
        if R == -1:
            return -1

        if abs(L - R) > 1:
            return -1

        return 1 + max(L, R)

    # TC : O(N)
    # SC : O(H) Recursive Stack Space
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.height(root) != -1