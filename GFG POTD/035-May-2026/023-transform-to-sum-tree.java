// https://www.geeksforgeeks.org/problems/transform-to-sum-tree/1/




/* Structure for Tree Node */
class Node {
    int data;
    Node left, right;

    // Constructor
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
};

class Solution {
    private int solve(Node root) {
        if (root == null) return 0;
        
        int L = solve(root.left);
        int R = solve(root.right);
        
        int temp = root.data;
        root.data = L + R;
        
        return L + R + temp;
    }
    public void toSumTree(Node root) {
        solve(root);
    }
}