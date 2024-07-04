# https://www.geeksforgeeks.org/problems/duplicate-subtrees/1



from collections import defaultdict

class Solution:
    # TC : O(N)
    # SC : O(N)
    def printAllDups(self, root):
        mpp = defaultdict(int)
        result = []
        self.solve(root, mpp, result)
        return result
        
    def solve(self, root, mpp, result):
        if not root:
            return "N"
            
        s = str(root.data)
        L = self.solve(root.left , mpp, result)
        R = self.solve(root.right, mpp, result)
        
        finalStr = s + L + R
        
        mpp[finalStr] += 1
        if mpp[finalStr] == 2:
            result.append(root)
        
        return finalStr


#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def build_tree(s):
    if not s or s[0] == 'N':
        return None

    ip = s.split()
    root = Node(int(ip[0]))
    queue = [root]
    i = 1

    while queue and i < len(ip):
        curr_node = queue.pop(0)
        curr_val = ip[i]

        if curr_val != 'N':
            curr_node.left = Node(int(curr_val))
            queue.append(curr_node.left)

        i += 1
        if i >= len(ip):
            break

        curr_val = ip[i]

        if curr_val != 'N':
            curr_node.right = Node(int(curr_val))
            queue.append(curr_node.right)

        i += 1

    return root


def preorder(root, temp):
    if not root:
        return
    temp.append(root.data)
    preorder(root.left, temp)
    preorder(root.right, temp)


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split('\n')
    t = int(data[0])
    index = 1
    for _ in range(t):
        s = data[index]
        index += 1
        root = build_tree(s)
        obj = Solution()
        res = obj.printAllDups(root)

        ans = []
        for node in res:
            temp = []
            preorder(node, temp)
            ans.append(temp)

        ans.sort(key=lambda x: x[0])

        for sublist in ans:
            print(" ".join(map(str, sublist)))

# } Driver Code Ends