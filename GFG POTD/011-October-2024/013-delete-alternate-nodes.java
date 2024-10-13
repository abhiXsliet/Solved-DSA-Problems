// https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1



//{ Driver Code Starts
/*package whatever //do not write package name here */
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}


// } Driver Code Ends
/*
class Node {
    int data;
    Node next;

    public Node(int data){
        this.data = data;
    }
}
*/
class Solution {
    public void deleteAlt(Node head) {
        Node prev = head;
        Node curr = head.next;
        while (curr != null) {
            Node forw = curr.next;
            prev.next = forw;
            prev = prev.next;
            curr.next = null;
            if (forw != null) {
                curr = forw.next;
            } else{
                curr = null;
            }
        }
    }
}


//{ Driver Code Starts.
public class GFG {
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
            for (int i = 1; i < arr.size(); i++) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            Solution ob = new Solution();
            ob.deleteAlt(head);
            printList(head);
        }
    }
}
// } Driver Code Ends