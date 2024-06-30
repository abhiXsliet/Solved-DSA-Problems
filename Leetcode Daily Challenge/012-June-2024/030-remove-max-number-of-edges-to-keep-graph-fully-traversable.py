# https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/



class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank   = [0] * (n + 1)
        self.components  = n
    
    def findParent(self, x):
        if x == self.parent[x]:
            return x

        self.parent[x] = self.findParent(self.parent[x])
        return self.parent[x]
    
    def unionSet(self, x, y):
        x_parent = self.findParent(x)
        y_parent = self.findParent(y)

        if x_parent > y_parent:
            self.parent[y_parent] = x_parent
        elif x_parent < y_parent:
            self.parent[x_parent] = y_parent
        else:
            self.parent[y_parent] = x_parent
            self.rank[x_parent]  += 1
        
        self.components -= 1

    def isSingleComponent(self):
        return self.components == 1

class Solution(object):
    # TC: O(M * log(M)) where M is the total number of edges
    #   + O(M * α(N)), where α is the inverse Ackermann function.
    #   Union-find operations take O(α(N)) time. Looping over all edges takes O(M) time, with each find and union operation inside the loop taking O(α(N)) time.
    
    # SC: O(N)
    def maxNumEdgesToRemove(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        alice = DSU(n)
        bob   = DSU(n)

        edges.sort(key = lambda x: -x[0])

        edgesCnt = 0

        for edge in edges:
            type, x, y = edge
            
            if type == 3: # both alice and bob can traverse the graph, so do union of both
                is_edge_added = False

                if alice.findParent(x) != alice.findParent(y):
                    alice.unionSet(x, y)
                    is_edge_added = True

                if bob.findParent(x) != bob.findParent(y):
                    bob.unionSet(x, y)
                    is_edge_added = True
                
                if is_edge_added:
                    edgesCnt += 1
                
            elif type == 2: # only bob can traverse the graph
                if bob.findParent(x) != bob.findParent(y):
                    bob.unionSet(x, y)
                    edgesCnt += 1

            else:  # only alice can traverse the graph
                if alice.findParent(x) != alice.findParent(y):
                    alice.unionSet(x, y)
                    edgesCnt += 1

        if alice.isSingleComponent() and bob.isSingleComponent():
            return len(edges) - edgesCnt

        return -1