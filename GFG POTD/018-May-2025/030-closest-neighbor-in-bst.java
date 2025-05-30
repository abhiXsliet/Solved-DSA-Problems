// https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1




import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}
class Solution {
    public int findMaxFork(Node root, int k) {
        // return approach_1(root, k);
        return approach_2(root, k);
    }
    
    // TC : O(H)
    // SC : O(H)
    private int approach_2(Node root, int k) {
        int ans = -1;
        while (root != null) {
            if (root.data <= k) {
                ans = root.data;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(H)
    private int approach_1(Node root, int k) {
        int[] ans = new int[]{-1};
        dfs(root, k, ans);
        return ans[0];
    }
    
    private void dfs(Node root, int k, int []ans) {
        if (root == null) return;
        
        if (root.data > ans[0] && root.data <= k) 
            ans[0] = root.data;
        
        dfs(root.left , k, ans);
        dfs(root.right, k, ans);
    }
}