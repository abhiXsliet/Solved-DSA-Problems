// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1




class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class Solution {
    // TC : O(N)
    // SC : O(1)
    public Node reverse(Node head) {
        Node prevN = null;
        Node curr  = head;
        
        while (curr != null) {
            Node forw = curr.next;
            curr.next = prevN;
            curr.prev = forw;
            
            prevN = curr;
            curr  = forw;
        }
        
        head = prevN;
        return head;
    }
}