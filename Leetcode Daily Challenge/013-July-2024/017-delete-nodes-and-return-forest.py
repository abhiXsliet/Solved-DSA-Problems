# Leetcode Daily Challenge/013-July-2024/017-delete-nodes-and-return-forest.cpp



# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def helper(self, root, st, result):
        if not root:
            return None

        root.left  = self.helper(root.left , st, result)
        root.right = self.helper(root.right, st, result)
        
        if root.val in st:
            if root.left:
                result.append(root.left)
            if root.right:
                result.append(root.right)
            return None # node has been deleted
        return root
    
    # TC : O(N)
    # SC : O(N)
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        result = []
        st = set(to_delete)

        root = self.helper(root, st, result)
        if root :
            result.append(root)
        return result