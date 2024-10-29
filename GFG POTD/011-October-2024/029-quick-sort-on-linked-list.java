// https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1




//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class SortLL {
    static Node head;

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            addToTheLast(head);

            for (int i = 1; i < n; i++) {
                int a = Integer.parseInt(str[i]);
                addToTheLast(new Node(a));
            }

            GfG gfg = new GfG();
            Node node = gfg.quickSort(head);

            printList(node);
            System.out.println();
        
System.out.println("~");
}
    }

    public static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }

    public static void addToTheLast(Node node) {
        if (head == null) {
            head = node;
        } else {
            Node temp = head;
            while (temp.next != null) temp = temp.next;
            temp.next = node;
        }
    }
}
// } Driver Code Ends


/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }

}*/
// you have to complete this function
class GfG {
    // TC : O(N*log(N))
    // SC : O(1)
    public static Node quickSort(Node head) {
        Node tail = getTail(head);
        solveQS(head, tail);
        return head;
    }
    private static Node getTail(Node head) {
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        return temp;
    }
    // TC : O(N*log(N))
    // SC : O(N) : Recursive Stack Space
    private static void solveQS(Node head, Node tail) {
        if (head == null || tail == null || head == tail)
            return;
        
        Node part = partation(head);
        solveQS(head, part);
        solveQS(part.next, tail);
    }
    private static Node partation(Node head) {
        // Make first node head as pivot node
        Node prev = head;
        Node curr = head.next;
        while (curr != null) {
            if (curr.data < head.data) {
                swap(curr, prev.next);
                prev = prev.next;
            }
            curr = curr.next;
        }
        // place pivot node as the correct position
        swap(head, prev);
        return prev;
    }
    private static void swap(Node a, Node b) {
        int c  = a.data;
        a.data = b.data;
        b.data = c;
    }
}