# https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1



#User function Template for python3
'''
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
'''
# TC : O(N)
# SC : O(N)
def compute(head): 
    store = getString(head)
    return isPalindrome(store)

# TC : O(N)
# SC : O(1)
def getString(head):
    store = ""
    while head is not None:
        store += head.data
        head   = head.next
    return store

# TC : O(N)
# SC : O(1)        
def isPalindrome(store):
    i, j = 0, len(store) - 1
    while i <= j:
        if store[i] != store[j]:
            return False
        i += 1
        j -= 1
    return True

#{ 
 # Driver Code Starts
#Initial Template for Python 3


#contributed by RavinderSinghPB
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class Llist:

    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):

        n1 = int(input())
        arr1 = input().split()
        ll1 = Llist()
        tail = None
        for nodeData in arr1:
            tail = ll1.insert(nodeData, tail)

        if compute(ll1.head):
            print('true')
        else:
            print('false')

# } Driver Code Ends