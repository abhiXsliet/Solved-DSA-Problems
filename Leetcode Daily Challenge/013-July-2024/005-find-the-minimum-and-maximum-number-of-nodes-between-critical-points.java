// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/



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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        return optimal(head);
    }

    // TC : O(N) Where N = No. of Nodes
    // SC : O(1)
    private static int[] optimal(ListNode head) {    
        int firstCriticalPt = 0;
        int prevCriticalPt = 0;
        int countOfNodes = 2;
        int minima = Integer.MAX_VALUE;

        while (head.next.next != null) {
            if ((head.next.val < head.val && head.next.val < head.next.next.val) ||
                (head.next.val > head.val && head.next.val > head.next.next.val)) {

                if (firstCriticalPt == 0) {
                    firstCriticalPt = countOfNodes;
                    prevCriticalPt = countOfNodes;
                } else {
                    minima = Math.min(minima, countOfNodes - prevCriticalPt);
                    prevCriticalPt = countOfNodes;
                }
            }
            head = head.next;
            countOfNodes++;
        }

        if (minima == Integer.MAX_VALUE)
            return new int[]{-1, -1};

        int maxima = prevCriticalPt - firstCriticalPt;
        return new int[]{minima, maxima};
    }
}