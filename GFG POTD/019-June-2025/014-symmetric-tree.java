// https://www.geeksforgeeks.org/problems/symmetric-tree/1




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
    // TC : O(N)
    // SC : O(H) where H is the height of the tree
    public boolean isSymmetric(Node root) {
        if (root == null) return true;
        
        return isMirror(root.left, root.right);
    }
    private boolean isMirror(Node r1, Node r2) {
        if (r1 == null || r2 == null) 
            return (r1 == null && r2 == null);
            
        if (r1.data != r2.data)
            return false;
            
        return (isMirror(r1.left, r2.right) && isMirror(r1.right, r2.left));
    }
}