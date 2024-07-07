// https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1




//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.LinkedList;

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

class Main {
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String s = br.readLine();
            Node root = buildTree(s);

            int target = Integer.parseInt(br.readLine());

            Solution g = new Solution();
            ArrayList<Integer> nodes = g.Ancestors(root, target);
            for (int i = 0; i < nodes.size(); i++) {
                System.out.print(nodes.get(i) + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


/*class Node of the binary tree
class Node
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}*/
class Solution {
    public ArrayList<Integer> Ancestors(Node root, int target) {
        // return approach_1(root, target);
        
        return approach_2(root, target);
    }
    
    // TC : O(N)
    // SC : O(H)
    private ArrayList<Integer> approach_2(Node root, int target) {
        List<Integer> temp   = new ArrayList<>();
        List<Integer> result = new ArrayList<>();
        func(root, target, temp, result);
        Collections.reverse(result);
        return new ArrayList<>(result);
    }

    // TC : O(N)
    // SC : O(H)
    private ArrayList<Integer> approach_1(Node root, int target) {
        List<Integer> result = new ArrayList<>();
        solve(root, target, result);
        return new ArrayList<>(result);
    }
    
    private void func(Node root, int tar, List<Integer> store, List<Integer> result) {
        if (root == null) return;

        if (root.data == tar) {
            result.addAll(store);
            return;
        }

        store.add(root.data);
        func(root.left, tar, store, result);
        func(root.right, tar, store, result);
        store.remove(store.size() - 1);
    }

    private boolean solve(Node root, int tar, List<Integer> result) {
        if (root == null) return false;

        if (root.data == tar) {
            // Found the target node, no need to continue searching
            return true;
        }

        // Check if the target node is an ancestor in the left subtree
        boolean foundInLeft = solve(root.left, tar, result);
        if (foundInLeft) {
            result.add(root.data);
            return true;
        }

        // Check if the target node is an ancestor in the right subtree
        boolean foundInRight = solve(root.right, tar, result);
        if (foundInRight) {
            result.add(root.data);
            return true;
        }

        return false;
    }
}