// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1/



class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
    
class Solution {
    public Node flatten(Node root) {
        return solve_iterative(root);
        // return solve_recursive(root);
    }
    
    public Node solve_recursive(Node root) {
        if (root == null || root.next == null)
            return root;
            
        root.next = solve_recursive(root.next);
        
        Node merged = mergeTwoSortedLLRecursive(root, root.next);
        merged.next = null;
        
        return merged;
    }
     
    public Node solve_iterative(Node root) {
        Node curr = null;
        Node temp = root;
        Node head = temp;
        while (temp != null) {
            Node merged = mergeTwoSortedLL(temp, curr);
            curr = merged;
            temp = temp.next;
            
            merged.next = null; // optional
        }
        return head;
    }
    
    public Node mergeTwoSortedLLRecursive(Node h1, Node h2) {
        if (h1 == null) return h2;
        if (h2 == null) return h1;
        
        Node result = null;
        
        if (h1.data <= h2.data) {
            result = h1;
            result.bottom = mergeTwoSortedLLRecursive(h1.bottom, h2);
        } else {
            result = h2;
            result.bottom = mergeTwoSortedLLRecursive(h1, h2.bottom);
        }
        
        result.next = null;
        return result;
    }
    
    public Node mergeTwoSortedLL(Node h1, Node h2) {
        if (h1 == null) return h2;
        if (h2 == null) return h1;
        
        Node curr1 = h1;
        Node curr2 = h2;
        
        Node newHead = new Node(-1);
        Node temp = newHead;
        
        while (curr1 != null && curr2 != null) {
            if (curr1.data < curr2.data) {
                temp.bottom = curr1;
                curr1 = curr1.bottom;
            } else {
                temp.bottom = curr2;
                curr2 = curr2.bottom;
            }
            temp = temp.bottom;
        }
        
        temp.bottom = (curr1 != null) ? curr1 : curr2;
        
        return newHead.bottom;
    }
}