// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/




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
    public ListNode deleteMiddle(ListNode head) {
        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next;
            if (fast.next != null) fast = fast.next;
        }

        if (prev == null) return null;
        else prev.next = slow.next;
        slow.next = null;

        return head;
    }
}