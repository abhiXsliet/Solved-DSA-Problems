# https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1



#User function Template for python3
"""
# Linked list Node class

    class Node :
        def __init__(self, val):
            self.data = val
            self.next = None

"""

class Solution:
    def removeAllDuplicates(self, head):
        # return self.approach_1(head)
        
        return self.approach_2(head)
        
    
    # TC : O(N)
    # SC : O(1)
    def approach_2(self, head):
        if not head.next:
            return None
            
        dummy = Node(0)
        dummy.next = head
        prev  = dummy
        curr  = head
        
        while curr and curr.next:
            if curr.data == curr.next.data:
                val = curr.data
                while curr and curr.data == val:
                    curr = curr.next
                prev.next = curr
            else:
                prev = curr
                curr = curr.next
                
        return dummy.next
    
    # TC : O(N)
    # SC : O(N)
    def approach_1(self, head):
        store = self.getNodes(head)
        return self.buildLL(store)
    
    def getNodes(self, head):
        store = []
        while head:
            store.append(head.data)
            head = head.next
        
        duplicateFree = []
        n = len(store)
        i = 0
        while i < n:
            j = i + 1
            while j < n and store[j] == store[i]:
                j += 1
            if j == i + 1:
                duplicateFree.append(store[i])
            i = j
            
        return duplicateFree
            
    def buildLL(self, store):
        if not store:
            return None
            
        head = Node(store[0])
        temp = head
        
        for i in range(1, len(store)):
            temp.next = Node(store[i])
            temp = temp.next
        
        return head
        
        
        
    
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


# Node Class
class Node:

    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node

    # prints the elements of linked list starting with head
    def printList(self, head):
        if head is None:
            print(' ')
            return
        curr_node = head
        while curr_node:
            print(curr_node.data, end=" ")
            curr_node = curr_node.next
        print(' ')


if __name__ == '__main__':
    t = int(input())
    for cases in range(t):
        N = int(input())
        a = LinkedList()  # create a new linked list 'a'.
        nodes = list(map(int, input().strip().split()))
        for x in nodes:
            a.append(x)
        ob = Solution()
        head = ob.removeAllDuplicates(a.head)
        a.printList(head)

# } Driver Code Ends