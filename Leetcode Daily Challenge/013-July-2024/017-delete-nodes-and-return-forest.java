// https://leetcode.com/problems/delete-nodes-and-return-forest/



/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private TreeNode helper(TreeNode root, Set<Integer> st, List<TreeNode> result) {
        if (root == null) return null;

        root.left  = helper(root.left , st, result);
        root.right = helper(root.right, st, result);

        if (st.contains(root.val)) {
            if (root.left  != null)
                result.add(root.left);
            if (root.right != null)
                result.add(root.right);
            root = null;
        } 
        return root;
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> result = new ArrayList<>();
        Set<Integer> st       = new HashSet<>();
        for (int num : to_delete) {
            st.add(num);
        }

        helper(root, st, result);

        if (!st.contains(root.val)) 
            result.add(root);
            
        return result;
    }
}