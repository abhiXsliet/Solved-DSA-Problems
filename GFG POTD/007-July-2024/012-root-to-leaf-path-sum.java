// https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1



//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG {
    public static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            int sum = Integer.parseInt(br.readLine().trim());
            Solution tr = new Solution();
            if (tr.hasPathSum(root, sum)) {
                System.out.println("true");
            } else {
                System.out.println("false");
            }
        }
    }
}
// } Driver Code Ends


/*
// A Binary Tree node
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
*/

class Solution {
    /*you are required to complete this function */
    boolean hasPathSum(Node root, int target) {
        // return approach_1(root, target);
        return approach_2(root, target);
    }

    // TC : O(N)
    // SC : O(H)
    private boolean approach_2(Node root, int target) {
        if (root == null) return false;
        if (root.left == null && root.right == null) 
            return target == root.data;
            
        return hasPathSum(root.left , target - root.data) || 
               hasPathSum(root.right, target - root.data);
    }
    
    // TC : O(N)
    // SC : O(H)
    private boolean approach_1(Node root, int target) {
        if (root.left == null && root.right == null && target == root.data) 
            return true;
        
        boolean left = false, right = false;
        if (root.left  != null) 
            left  = hasPathSum(root.left , target - root.data);
        if (root.right != null) 
            right = hasPathSum(root.right, target - root.data);
            
        return left || right;
    }
}
