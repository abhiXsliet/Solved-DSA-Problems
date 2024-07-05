# https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/




# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        return self.optimal(head)

    # TC : O(N)
    # SC : O(1)
    def optimal(self, head):
            first_critical_pt = 0
            prev_critical_pt = 0
            count_of_nodes = 2
            minima = float('inf')

            while head.next.next:
                if ((head.next.val < head.val and head.next.val < head.next.next.val) or
                    (head.next.val > head.val and head.next.val > head.next.next.val)):

                    if first_critical_pt == 0:
                        first_critical_pt = count_of_nodes
                        prev_critical_pt = count_of_nodes
                    else:
                        minima = min(minima, count_of_nodes - prev_critical_pt)
                        prev_critical_pt = count_of_nodes

                head = head.next
                count_of_nodes += 1

            if minima == float('inf'):
                return [-1, -1]

            maxima = prev_critical_pt - first_critical_pt
            return [minima, maxima]