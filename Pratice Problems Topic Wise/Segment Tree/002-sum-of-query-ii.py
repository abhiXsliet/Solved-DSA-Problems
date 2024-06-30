# https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1



#User function Template for python3
class Solution:
    # TC : O(N) + O(Q*log(N)) Where N = Size of Array & Q = Number of queries
    # SC : O(N)
    def querySum(self, n, arr, q, queries):
        segTree = [0] * (4 * n);
        
        self.buildTree(0, 0, n - 1, arr, segTree)
        
        result = []
        
        for i in range (0, 2 * q, 2):
            startQ = queries[i] - 1
            endQ   = queries[i + 1] - 1
            result.append(self.Query(0, 0, n - 1, startQ, endQ, segTree));
            
        return result
        
    # TC : O(N)
    # SC : O(N)
    def buildTree(self, i, l, r, arr, segTree):
        if l == r:
            segTree[i] = arr[l]
            return
        
        mid = (l + r) >> 1 # mid = (l + r) // 2
        self.buildTree(2*i + 1, l, mid, arr, segTree)
        self.buildTree(2*i + 2, mid + 1, r, arr, segTree)
        
        segTree[i] = segTree[2*i + 1] + segTree[2*i + 2]
     
    # TC : O(log(N))
    # SC : O(1)
    def Query(self, i, l, r, startQ, endQ, segTree):
        if l > endQ or r < startQ:  # out of bound
            return 0
            
        if l >= startQ and r <= endQ:   # completely overlap
            return segTree[i];
        
        mid = (l + r) >> 2
        return self.Query(2*i + 1, l, mid, startQ, endQ, segTree) + \
        self.Query(2*i + 2, mid + 1, r, startQ, endQ, segTree)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = input().split()
        for i in range(n):
            arr[i] = int(arr[i])
        q = int(input())
        queries = input().split()
        for i in range(0,2*q,2):
            queries[i] = int(queries[i])
            queries[i+1] = int(queries[i+1])
        
        ob = Solution()
        ans = ob.querySum(n, arr, q, queries)
        for it in(ans):
            print(it,end=" ")
        print()
# } Driver Code Ends