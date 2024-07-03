// https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1



//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GFG {
    Node head;
    Node tail;

    public void addToTheLast(Node node) {
        if (head == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            tail = node;
        }
    }

    void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    /* Drier program to test above functions */
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            GFG llist = new GFG();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < N; i++) {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }

            Solution ob = new Solution();
            head = ob.removeAllDuplicates(llist.head);
            llist.printList(head);

            t--;
        }
    }
}
// } Driver Code Ends


class Solution {
    public Node removeAllDuplicates(Node head) {
        // return approach_1(head);
        
        return approach_2(head);
    }
    
    // TC : O(N)
    // SC : O(1)
    private static Node approach_2(Node head) {
        Node dummy = new Node(0);
        dummy.next = head;
        Node prev  = dummy;
        Node curr  = head;
        
        while (curr != null && curr.next != null) {
            if (curr.data == curr.next.data) {
                int val = curr.data;
                while(curr != null && curr.data == val)
                    curr = curr.next;
                prev.next = curr;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
        
        return dummy.next;
    }
    
    // TC : O(N)
    // SC : O(N)
    private static Node approach_1(Node head) {
        List<Integer> store = new ArrayList<>();
        getNodes(head, store);
        return buildLL(store);
    }
    
    private static void getNodes(Node head, List<Integer> store) {
        while (head != null) {
            store.add(head.data);
            head = head.next;
        }
        
        List<Integer> duplicateFree = new ArrayList<>();
        int n = store.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && store.get(i).equals(store.get(j))) j ++;
            if (i + 1 == j) {
                duplicateFree.add(store.get(i));
            }
            i = j;
        }
        store.clear();
        store.addAll(duplicateFree);
    }
    
    private static Node buildLL(List<Integer> store) {
        if (store.isEmpty()) return null;
        
        Node head = new Node(store.get(0));
        Node temp = head;
        for (int i = 1; i < store.size(); i++) {
            temp.next = new Node(store.get(i));
            temp = temp.next;
        }

        return head;
    }
}