// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/




class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    public Node intersectPoint(Node head1, Node head2) {
        // return approach_1(head1, head2);    // len diff method
        return approach_2(head1, head2);    // without len diff method: start from head after reaching end of linkedlist
    }
    
    // TC : O(n + m)
    // SC : O(1)
    public Node approach_2(Node headA, Node headB) {
        if (headA == null || headB == null) return null;

        Node p1 = headA;
        Node p2 = headB;

        while (p1 != p2) {
            p1 = (p1 == null) ? headB : p1.next;
            p2 = (p2 == null) ? headA : p2.next;
        }

        return p1;
    }
    
    // TC : O(n + m)
    // SC : O(1)
    public Node approach_1(Node head1, Node head2) {
        int len1 = getLen(head1);
        int len2 = getLen(head2);
        int diff = Math.abs(len1 - len2);
        
        Node curr1 = head1;
        Node curr2 = head2;
        
        if (len1 > len2) {
            for (int i = 0; i < diff; i ++) { 
                curr1 = curr1.next;
            }
        } else {
            for (int i = 0; i < diff; i ++) {
                curr2 = curr2.next;
            }
        }
        
        while (curr1 != null) {
            if (curr1 == curr2) {
                return curr1;
            } else {
                curr1 = curr1.next;
                curr2 = curr2.next;
            }
        }
        
        return null;
    }
    private int getLen(Node head) {
        Node temp = head;
        int len = 1;
        while (temp != null) {
            len ++;
            temp = temp.next;
        }
        return len;
    }
}