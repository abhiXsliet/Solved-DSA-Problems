// https://www.geeksforgeeks.org/problems/find-length-of-loop/1/




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
    public int lengthOfLoop(Node head) {
        Node slow = head;
        Node fast = head;
        
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                int cycleNodes = 1;
                slow = slow.next;
                while (slow != fast) {
                    slow = slow.next;
                    cycleNodes += 1;
                }
                return cycleNodes;
            }
        }
        
        return 0;
    }
}