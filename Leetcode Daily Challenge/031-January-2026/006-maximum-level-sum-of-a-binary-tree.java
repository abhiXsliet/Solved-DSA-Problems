// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/




import java.util.*;

// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
};

class Solution {
    public int maxLevelSum(TreeNode root) {
        // return approach_1(root);    // BFS
        return approach_2(root);    // dfs
    }

    private int approach_2(TreeNode root) {
        HashMap<Integer, Integer> hmp = new HashMap<>();
        dfs(root, 1, hmp);

        int maxLevel = 1, maxSum = Integer.MIN_VALUE;
        for (Map.Entry<Integer, Integer> entry : hmp.entrySet()) {
            int level = entry.getKey();
            int sum = entry.getValue();
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
        }
        return maxLevel;
    }

    // TC : O(N)
    // SC : O(N)
    private int approach_1(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int level = 1;
        int maxSum = Integer.MIN_VALUE, maxLevel = level;
        while (!q.isEmpty()) {
            int size = q.size();
            int sum = 0;
            while (size -- > 0) {
                TreeNode frnt = q.poll();
                sum += frnt.val;
                if (frnt.left  != null) q.add(frnt.left);
                if (frnt.right != null) q.add(frnt.right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
            level ++;
        }
        return maxLevel;
    }

    private void dfs(TreeNode root, int currLevel, HashMap<Integer, Integer> hmp) {
        if (root == null) return;

        hmp.put(currLevel, hmp.getOrDefault(currLevel, 0) + root.val);

        dfs(root.left, currLevel + 1, hmp);
        dfs(root.right, currLevel + 1, hmp);
    }
}