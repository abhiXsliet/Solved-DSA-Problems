// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/



// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public int getDecimalValue(ListNode head) {
        int decimal = 0;
        ListNode temp = head;
        while (temp != null) {
            decimal = (decimal * 2) + temp.val;
            temp = temp.next;
        }
        return decimal;
    }
}