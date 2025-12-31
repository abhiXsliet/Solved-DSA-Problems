// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/




class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    public boolean isPalindrome(Node head) {
        // return approach_1(head);    // modification in ll
        
        Node[] h1 = new Node[]{head};
        return approach_2(h1, head);    // no-modification in ll
    }
    
    private boolean approach_2(Node[] h1, Node h2) {
        if (h2 == null) return true;
        
        boolean ans = approach_2(h1, h2.next);
        
        if (h1[0].data != h2.data) return false;
        h1[0] = h1[0].next;
        return ans;
    }
    
    private boolean approach_1(Node head) {
        Node slow = head;
        Node fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        fast = reverseRec(slow.next);
        slow = head;
        while (fast != null) {
            if (slow.data == fast.data) {
                fast = fast.next;
                slow = slow.next;
            } else return false;
        }
        return true;
    }
    private Node reverseRec(Node head) {
        if (head == null || head.next == null)
            return head;
            
        Node headNex = reverseRec(head.next);
        head.next.next = head;
        head.next = null;
        
        return headNex;
    }
}