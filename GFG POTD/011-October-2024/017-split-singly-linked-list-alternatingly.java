// https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1




//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}
// } Driver Code Ends

// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    Node[] alternatingSplitList(Node head) {
        if (head.next == null) 
            return new Node[] {head, null};
        
        Node newH1 = head;
        Node newH2 = head.next;
        Node temp1 = newH1;
        Node temp2 = newH2;

        while(temp1 != null && temp1.next != null 
           && temp2 != null && temp2.next != null) {
            temp1.next = temp1.next.next;
            temp2.next = temp2.next.next;
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        
        if (temp1 != null) temp1.next = null;
        if (temp2 != null) temp2.next = null;
        
        return new Node[] {newH1, newH2};
    }
}
