// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    private final int M = 1000_000_007;
    private int totalSum = 0;
    private long maxProd = 0L;

    private void dfs(TreeNode root) {
        if (root == null) return;

        totalSum += root.val;

        dfs(root.left);
        dfs(root.right);
    }

    private int getMaxProd(TreeNode root, int tSum) {
        if (root == null) return 0;

        long left  = getMaxProd(root.left, tSum);
        long right = getMaxProd(root.right, tSum);

        maxProd = Math.max(maxProd, ((tSum - left) * left));
        maxProd = Math.max(maxProd, ((tSum - right) * right));

        return (int)(left + right + root.val);
    }
    public int maxProduct(TreeNode root) {
        dfs(root);
        getMaxProd(root, totalSum);
        return (int)(maxProd % M);
    }
}