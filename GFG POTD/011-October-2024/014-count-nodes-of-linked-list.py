# https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1



#User function Template for python3
'''
#Linked list class
class LinkedList:
    def __init__(self):
        self.head=None
        self.tail=None
        '''
class Solution:
    # Function to count nodes of a linked list.
    def getCount(self, head):
        cnt = 0
        temp = head
        while temp is not None:
            cnt  = cnt + 1
            temp = temp.next
        return cnt


#{ 
 # Driver Code Starts
#Initial Template for Python 3
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split('\n')

    t = int(data[0])
    for i in range(1, t + 1):
        arr = list(map(int, data[i].split()))
        head = Node(arr[0])
        tail = head
        for value in arr[1:]:
            tail.next = Node(value)
            tail = tail.next
        ob = Solution()
        print(ob.getCount(head))

# } Driver Code Ends