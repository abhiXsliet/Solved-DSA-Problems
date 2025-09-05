// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1/




class Node {
    int data;
    Node next;
    Node (int d) {
        data = d;
        next = null;
    }
}

class Solution {
    // TC : O(N)
    // SC : O(1)
    public Node segregate(Node head) {
        int[] count = new int[3];
        Node temp = head;
        
        while (temp != null) {
            count [temp.data] ++;
            temp = temp.next;
        }
        
        int i = 0;
        temp = head;
        
        while (true) {
            while (temp != null && count[i] -- > 0) {
                temp.data = i;
                temp = temp.next;
            }
            i ++;
            if (i == 3) break;
        }
        
        return head;
    }
}