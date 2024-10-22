// Leetcode Daily Challenge/016-October-2024/022-kth-largest-sum-in-a-binary-tree.cpp



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
}

class Solution {
    // TC : O(N * log(K))
    // SC : O(N)
    public long kthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();
            long sum = 0;
            while (size -- > 0) {
                TreeNode fNode = q.poll();
                sum += (fNode.val);
                if (fNode.left  != null) q.add(fNode.left);
                if (fNode.right != null) q.add(fNode.right);
            }
            pq.add(sum);
            if (pq.size() > k) pq.poll();
        }

        return pq.size() < k ? -1 : pq.peek();
    }
}