// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1/




class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Solution {
    public Node reverseKGroup(Node head, int k) {
        // return approach_1(head, k);     // Iterative
        return approach_2(head, k);     // Recursive 
    }
    
    // TC : O(N)
    // SC : O(K) Recursive Stack space
    private Node approach_2(Node head, int k) {
        if (head == null || head.next == null)
            return head;
            
        Node curr = head;
        Node prev = null;
        Node forw = null;
        int count = k;
        
        while (curr != null && count -- > 0) {
            forw = curr.next;
            curr.next = prev;
            prev = curr;
            curr = forw;
        }
        
        if (forw != null) {
            head.next = approach_2(curr, k);
        }
        
        return prev;
    }
    
    // TC : O(N)
    // SC : O(1)
    private Node approach_1(Node head, int k) {
        Node temp = head, prev = null;
        while (temp != null) {
            Node kthNode = getKthNode(temp, k);
            
            if (kthNode == null) {
                if (prev != null) prev.next = reverseRec(temp);
                break;
            }
            
            Node kthNextNode = kthNode.next;
            kthNode.next = null;
            
            reverseRec(temp);
            
            if (temp == head) {
                head = kthNode;
            } else {
                prev.next = kthNode;
            }
            
            prev = temp;
            temp = kthNextNode;
        }
        return head;
    }
    
    private Node getKthNode(Node temp, int k) {
        while (temp != null && k > 1) {
            temp = temp.next;
            k --;
        }
        return (k == 1) ? temp : null;
    }
    
    private Node reverse(Node head) {
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
            
        Node nextNode = reverseRec(head.next);
        head.next.next = head;
        head.next = null;
        
        return nextNode;
    }
}