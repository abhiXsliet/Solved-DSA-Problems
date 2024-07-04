// https://leetcode.com/problems/merge-nodes-in-between-zeros/



import java.util.*;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        // return approach_1(head);

        return approach_2(head);
    }

    // TC : O(N)
    // SC : O(1)
    private static ListNode approach_1(ListNode head) {
        ListNode prev = head.next;
        ListNode curr = head.next;

        while (curr != null) {
            int sum = 0;
            while (curr.val != 0) {
                sum += curr.val;
                curr = curr.next;
            }
            prev.val = sum;
            curr = curr.next;
            prev.next = curr;
            prev = prev.next;
        }
        return head.next;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Call stack
    private static ListNode approach_2(ListNode head) {
        head = head.next;
        if (head == null) return head;

        ListNode curr = head;
        int sum = 0;
        while (curr != null && curr.val != 0) {
            sum += curr.val;
            curr = curr.next;
        }
        head.val  = sum;
        head.next = approach_2(curr);
        return head;
    }
}