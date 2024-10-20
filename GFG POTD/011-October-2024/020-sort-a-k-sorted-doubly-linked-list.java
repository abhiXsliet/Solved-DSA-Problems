// https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1



//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class DLLNode {
    int data;
    DLLNode next;
    DLLNode prev;

    DLLNode(int val) {
        data = val;
        next = null;
        prev = null;
    }
}

public class Main {
    public static void push(DLLNode tail, int new_data) {
        DLLNode newNode = new DLLNode(new_data);
        newNode.next = null;
        newNode.prev = tail;

        if (tail != null) {
            tail.next = newNode;
        }
    }

    public static void printList(DLLNode head) {
        if (head == null) {
            return;
        }

        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String[] arr = br.readLine().trim().split(" ");
            int k = Integer.parseInt(br.readLine().trim());

            DLLNode head = new DLLNode(Integer.parseInt(arr[0]));
            DLLNode tail = head;

            for (int i = 1; i < arr.length; i++) {
                push(tail, Integer.parseInt(arr[i]));
                tail = tail.next;
            }

            Solution obj = new Solution();
            DLLNode sorted_head = obj.sortAKSortedDLL(head, k);
            printList(sorted_head);
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    public DLLNode sortAKSortedDLL(DLLNode head, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();  
        
        DLLNode temp = head;
        int cnt      = k + 1;
        while (cnt -- > 0) {
            pq.add(temp.data);
            temp = temp.next;
        }
        
        DLLNode curr = head;
        while (temp != null && !pq.isEmpty()) {
            int v = pq.poll();
            curr.data = v;
            curr = curr.next;
            pq.add(temp.data);
            temp = temp.next;
        }
        while (!pq.isEmpty()) {
            int v = pq.poll();
            curr.data = v;
            curr = curr.next;
        }
        
        return head;
    }
}