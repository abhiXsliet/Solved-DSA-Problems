// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/




import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class Solution {
    // TC : O(N*log(N))
    // SC : O(N)
    Node mergeKLists(Node[] arr) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data);
        for (Node v : arr) {
            if (v != null) {
                pq.add(v);
            }
        }
        
        Node head = null, temp = null;
        
        while (!pq.isEmpty()) {
            Node topN = pq.poll();
            
            if (topN.next != null) pq.add(topN.next);
            
            if (head == null) {
                head = topN;
                temp = head;
            } else {
                temp.next = topN;
                temp = temp.next;
            }
        }
        
        return head;
    }
}