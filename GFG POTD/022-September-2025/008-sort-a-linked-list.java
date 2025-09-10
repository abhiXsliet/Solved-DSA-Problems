// https://www.geeksforgeeks.org/problems/sort-a-linked-list/1/




class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class Solution {
    // TC : O(N*log(N))
    // SC : O(1)
    public Node mergeSort(Node head) {
        if (head == null || head.next == null)
            return head;
            
        Node mid   = getMid(head);
        Node midN  = mid.next;
        mid.next   = null;
        
        Node left  = mergeSort(head);
        Node right = mergeSort(midN);
        
        return mergeOptimal(left, right);
    }
    
    // TC : O(N)
    // SC : O(1)
    private static Node getMid(Node head) {
        Node fast = head;
        Node slow = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    
    // TC : O(N)
    // SC : O(1)
    private static Node mergeOptimal(Node l1, Node l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        
        if (l1.data <= l2.data) {
            l1.next = mergeOptimal(l1.next, l2);
            return l1;
        }
        
        l2.next = mergeOptimal(l1, l2.next);
        return l2;
    }
    
    // TC : O(N)
    // SC : O(N)
    private static Node merge(Node l1, Node l2) {
        Node dummy = new Node(-1);
        Node temp  = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.data <= l2.data) {
                temp.next = l1;
                l1 = l1.next;
            } else {
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }
        
        if (l1 != null) temp.next = l1;
        else temp.next = l2;
        
        return dummy.next;
    }
}