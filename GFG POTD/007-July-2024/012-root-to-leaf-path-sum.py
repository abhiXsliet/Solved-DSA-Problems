# https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1



#User function Template for python3
'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''


class Solution:
    def hasPathSum(self, root, target):
        '''
        :param root: root of given tree.
        :param sm: root to leaf sum
        :return: true or false
        '''
        # return self.approach_1(root, target)
        return self.approach_2(root, target)

    # TC : O(N)
    # SC : O(H)
    def approach_2(self, root, target) :
        if root is None:
            return False
        if root.left is None and root.right is None : 
            return target == root.data
            
        return (self.hasPathSum(root.left, target - root.data) or 
               self.hasPathSum(root.right, target - root.data))
    
    # TC : O(N)
    # SC : O(H)
    def approach_1(self, root, target) :
        if root.left is None and root.right is None and target == root.data : 
            return True
        
        left, right = False, False
        if root.left :
            left  = self.hasPathSum(root.left , target - root.data)
        if root.right :
            right = self.hasPathSum(root.right, target - root.data)
            
        return (left or right)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque


# Tree Node
class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    #Corner Case
    if (len(s) == 0 or s[0] == "N"):
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):

            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):

            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s = input()
        root = buildTree(s)
        sum = int(input())
        if Solution().hasPathSum(root, sum) == True:
            print("true")
        else:
            print("false")

# } Driver Code Ends