# https://leetcode.com/problems/merge-nodes-in-between-zeros/




# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # return self.approach_1(head)

        return self.approach_2(head)

    # TC : O(N)
    # SC : O(1)
    def approach_1(self, head):
        prev = head.next
        curr = head.next

        while curr:
            sum = 0
            while curr and curr.val != 0:
                sum += curr.val
                curr = curr.next
            prev.val = sum
            curr = curr.next
            prev.next = curr
            prev = prev.next
        return head.next

    # TC : O(N)
    # SC : O(N) -> Recursive Call Stack Space
    def approach_2(self, head):
        head = head.next
        if not head:
            return head
        
        curr = head
        sum  = 0
        
        while curr and curr.val != 0:
            sum += curr.val
            curr = curr.next
        
        head.val  = sum
        head.next = self.approach_2(curr)
        return head
        