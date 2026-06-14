// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/




/**
Definition for singly-linked list.
*/
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    private ListNode reverse(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode nextNode = reverse(head.next);
        head.next.next = head;
        head.next = null;

        return nextNode;
    }

    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        fast = slow.next;
        slow.next = null;

        ListNode rev   = reverse(fast);
        ListNode temp1 = head;
        ListNode temp2 = rev;

        int ans = Integer.MIN_VALUE;
        while (temp1 != null && temp2 != null) {
            ans = Math.max(ans, temp1.val + temp2.val);
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        return ans;
    }
}