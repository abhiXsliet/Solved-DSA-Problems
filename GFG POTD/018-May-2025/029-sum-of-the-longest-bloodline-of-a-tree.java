// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1




class Node {
    int data;
    Node left, right;

    public Node(int data){
        this.data = data;
    }
}

class Solution {
    public int sumOfLongRootToLeafPath(Node root) {
        return dfs(root, 0).sum;
    }
    
    class Pair {
        int sum;
        int depth;
        Pair(int sum, int depth) {
            this.sum = sum;
            this.depth = depth;
        }
    }
    
    private Pair dfs(Node root, int depth) {
        if (root == null) {
            return new Pair(0, depth);
        }
        
        Pair left  = dfs(root.left, depth + 1);
        Pair right = dfs(root.right, depth + 1);
        
        if (left.depth >= right.depth) {
            if (left.depth == right.depth) {
                int val = left.sum > right.sum ? left.sum : right.sum;
                return new Pair(val + root.data, left.depth);
            }
            return new Pair(root.data + left.sum, left.depth);
        }
        return new Pair(root.data + right.sum, right.depth);
    }
}