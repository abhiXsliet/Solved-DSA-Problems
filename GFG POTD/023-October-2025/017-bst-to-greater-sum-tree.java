// https://www.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1/




class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

class Solution {
    private static int sum = 0;
    
    // TC : O(N)
    // SC : O(1)
    public static void transformTree(Node root) {
        sum = 0;
        solve(root);
    }
    
    private static void solve(Node root) {
        if (root == null) return;
        
        solve(root.right);
        
        int temp = root.data;
        root.data = sum;
        sum += temp;
        
        solve(root.left);
    }
}