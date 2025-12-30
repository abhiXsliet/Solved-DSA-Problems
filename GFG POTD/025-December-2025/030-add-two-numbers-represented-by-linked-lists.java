// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1/



class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    public Node addTwoLists(Node head1, Node head2) {
        // Trim leading zeros
        while (head1 != null && head1.data == 0) {
            head1 = head1.next;
        }
        while (head2 != null && head2.data == 0) {
            head2 = head2.next;
        }
        
        head1 = reverseIter(head1);
        head2 = reverseIter(head2);
        
        Node temp = new Node(-1);
        Node head = temp;
        Node curr1 = head1;
        Node curr2 = head2;
        int carry = 0;
        
        while (curr1 != null || curr2 != null) {
            int val = carry;
            if (curr1 != null) {
                val += curr1.data;
                curr1 = curr1.next;
            }
            if (curr2 != null) {
                val += curr2.data;
                curr2 = curr2.next;
            }
            
            carry = val / 10;
            val %= 10;
            
            temp.next = new Node(val);
            temp = temp.next;
        }
        
        if (carry % 2 != 0) temp.next = new Node(carry);
        
        return reverseRec(head.next);
    }
    private Node reverseIter(Node head) {
        Node curr = head;
        Node prev = null;
        while (curr != null) {
            Node forw = curr.next;
            curr.next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
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