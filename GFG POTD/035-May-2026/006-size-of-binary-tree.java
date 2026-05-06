// https://www.geeksforgeeks.org/problems/size-of-binary-tree/1/




/*
Definition for Node
*/
class Node
{
    int data;
    Node left;
    Node right;

    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
    private void solve(Node root, int[] res) {
        if (root == null) return;
        
        res[0] = res[0] + 1;
        solve(root.left, res);
        solve(root.right, res);
    }
    public int getSize(Node root) {
        int[] res = new int[1];
        solve(root, res);
        return res[0];
    }
}