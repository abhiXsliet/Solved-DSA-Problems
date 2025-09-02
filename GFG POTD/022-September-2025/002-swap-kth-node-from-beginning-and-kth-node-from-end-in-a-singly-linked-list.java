// https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1




class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {
    // TC : O(N)
    // SC : O(1)
    public Node swapKth(Node head, int k) {
        Node curr   = head;
        Node first  = null;
        Node second = head;
        int count   = 1;
        
        while (curr != null) {
            if (count == k) first = curr;
            if (count  > k) second = second.next;
            
            curr = curr.next;
            count += 1;
        }
        
        if (first == null) return head; // k > nodesCnt
        
        int temp    = first.data;
        first.data  = second.data;
        second.data = temp;
        
        return head;
    }
}
