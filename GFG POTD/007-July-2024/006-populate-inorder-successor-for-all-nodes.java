// https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1




//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node left, right, next;

    public Node(int data) { this.data = data; }
}

class GFG {

    static Node buildTree(String str) {

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

    public static void inorder(Node root) {
        if (root == null) return;

        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static Node Inorder(Node root) {
        if (root.left == null) return root;
        return Inorder(root.left);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution obj = new Solution();
            obj.populateNext(root);
            Node ptr = Inorder(root);
            while (ptr != null) {
                System.out.print(ptr.data + "->" +
                                 (ptr.next != null ? ptr.next.data : -1) + " ");

                ptr = ptr.next;
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends

// User function Template for Java
/*
class Node {
    int data;
    Node left, right,next;

    public Node(int data){
        this.data = data;
    }
}
*/
class Solution {
    public void populateNext(Node root) {
        // approach_1(root);
        
        approach_2(root);
    }
    
    // TC : O(N)
    // SC : O(1)
    static Node prev = null;
    private static void approach_2(Node root) {
        if (root == null) return;
        
        approach_2(root.left);
        if (prev != null) {
            prev.next = root;
        }
        prev = root;
        approach_2(root.right);
    }
    
    // TC : O(N)
    // SC : O(N)
    private static void approach_1(Node root) {
        List<Node> store = new ArrayList<>();
        
        inorder(root, store);
        
        for (int i = 0; i < store.size() - 1; i++) {
            store.get(i).next = store.get(i + 1);
        }
    }
    
    private static void inorder(Node root, List<Node> store) {
        if (root == null) return;
        
        inorder(root.left , store);
        store.add(root);
        inorder(root.right, store);
    }
}