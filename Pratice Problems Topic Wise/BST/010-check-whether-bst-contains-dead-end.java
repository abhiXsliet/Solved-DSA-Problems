// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1



//{ Driver Code Starts

import java.util.*;
class Node {
        int data;
        Node left, right;
 
        Node(int item) {
            data = item;
            left = right = null;
        }
    }
class BinarySearchTree {
    public static Node root;
    BinarySearchTree() { 
        root = null; 
    }
    void insert(int key) {
       root = insertRec(root, key);
    }
    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data)
            root.left = insertRec(root.left, key);
        else if (key > root.data)
            root.right = insertRec(root.right, key);
        return root;
    }
 
    public static void inorder()  {
       inorderRec(root);
    }
    public static void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data);
            inorderRec(root.right);
        }
    }
 
    // Driver Program to test above functions
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int []a=new int[n];
            BinarySearchTree obj1=new BinarySearchTree();
            for(int i=0;i<n;i++)
            {
                int b=sc.nextInt();
                obj1.insert(b);
            }
            //inorder();
            Solution obj=new Solution();
            boolean k=obj.isDeadEnd(root);
            if(k==true)
            System.out.println("1");
            else
            System.out.println("0");
        }       
    }
}
// } Driver Code Ends


/*class Node {
        int data;
        Node left, right;
 
        Node(int item) {
            data = item;
            left = right = null;
        }
    }*/

//Function should return true if a deadEnd is found in the bst otherwise return false.
class Solution
{
    public static boolean isDeadEnd(Node root)
    {
        // return approach_1(root);
        
        return approach_2(root, 1, 10001);
    }
    
    // TC : O(N)
    // SC : O(N)
    private static boolean approach_1(Node root) {
        Set<Integer> leaf     = new HashSet<>();
        Set<Integer> nonLeaf = new HashSet<>();
        
        nonLeaf.add(0);
        preorder(root, leaf, nonLeaf);
        
        for (int i : leaf) {
            if (nonLeaf.contains(i + 1) && nonLeaf.contains(i - 1)) {
                return true;
            }
        }
        
        return false;
    }
    
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    private static boolean approach_2(Node root, int mini, int maxi) {
        if (root == null) return false;
        
        if (root.data == mini && root.data == maxi)
            return true;
        
        return (approach_2(root.left , mini, root.data - 1) || 
                approach_2(root.right, root.data + 1, maxi));
    }
    
    // TC : O(N)
    // SC : O(N) -> Depth of Recursion
    private static void preorder(Node root, Set<Integer> leaf, Set<Integer> nonLeaf) {
        if (root == null) return;
        
        if (root.left == null && root.right == null)
            leaf.add(root.data);
        else 
            nonLeaf.add(root.data);
            
        preorder(root.left , leaf, nonLeaf);
        preorder(root.right, leaf, nonLeaf);
    }
}

