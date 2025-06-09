// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
}

class Solution {
    public boolean isDeadEnd(Node root) {
        return solve(root, 0, Integer.MAX_VALUE);
    }
    // TC : O(N)
    // SC : O(H)
    private boolean solve(Node root, int mini, int maxi) {
        if (root == null) return false;
        if (root.left == null && root.right == null) {
            return ((root.data - mini == 1) && (maxi - root.data == 1));
        }
        
        boolean L = solve(root.left, mini, root.data);
        boolean R = solve(root.right, root.data, maxi);
        
        return L || R;
    }
}