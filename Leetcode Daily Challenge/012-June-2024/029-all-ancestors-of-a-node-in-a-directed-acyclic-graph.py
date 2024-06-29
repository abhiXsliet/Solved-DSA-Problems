# https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/



from collections import defaultdict, deque, List

class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # return self.approach_1(n, edges)  # Mark 'u' as an ancestor and traverse adjacent nodes to update their ancestors as node 'u'

        # return self.approach_2(n, edges)   # Reverse the graph: For each node 'u', traverse its adjacent nodes to identify which nodes consider 'u' as an ancestor, marking these nodes as true during the traversal.

        return self.approach_3(n, edges)    # Get Topological Sort, then find their ancestor of ancestor nodes

    # TC : O(V^2 + (V+E) + Vlog(V)) -> O(V+E) for building the graph and performing the topological sort, 
    #                               -> O(V^2) for processing each node and merging ancestor lists.
    #                               -> O(VlogV) for sorting the ancestor lists for each node.
    # SC : O(V^2 + E)
    def approach_3(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = defaultdict(list)
        inDegree = [0] * n
        for u, v in edges:  # O(V + E)
            adj[u].append(v)
            inDegree[v] += 1
        
        result = [[] for _ in range(n)]

        # Find TopoSort and find its ancestor of ancestor nodes
        topoSort = self.BFS(inDegree, adj)  # Kahn's algorithm

        # To find ancestor of ancestors : use list of sets
        vec = [set() for _ in range(n)]

        for node in topoSort:   # O(V*)
            for v in adj[node]: 
                vec[v].add(node)    # add node as ancestor of v
                vec[v].update(vec[node])    # add ancestor of node

        result = []
        for i in range(n):
            ancestor = sorted(vec[i])
            result.append(ancestor)
        return result


    # TC : O(V*(V + E))
    # SC : O(V + E)
    def approach_2(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = defaultdict(list)
        for u, v in edges:
            adj[v].append(u)

        result = [[] for _ in range(n)]

        for u in range(n):
            ancestor = []
            visited = [False] * n
            self.dfs(u, visited, adj)
            for i in range(n):
                if i == u:
                    continue
                if visited[i]: # node 'i' traverse and marked true means node 'u' was its ancestor
                    ancestor.append(i)
            result[u] = ancestor
        return result 

             

    # TC : O(V*(V + E))
    # SC : O(V + E)
    def approach_1(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
        
        result = [[] for _ in range(n)]

        for u in range(n):
            ancestor = u
            self.DFS(u, ancestor, adj, result)

        return result

    # TC : O(V + E)
    # SC : O(V + E) : Recursive Depth
    def DFS(self, currNode, ancestor, adj, result):
        for nbr in adj[currNode]:
            if not result[nbr] or result[nbr][-1] != ancestor: # to avoid duplicacy
                result[nbr].append(ancestor)
                self.DFS(nbr, ancestor, adj, result)

    # TC : O(V + E)
    # SC : O(V + E) : Recursive Depth
    def dfs(self, currNode, visited, adj):
        visited[currNode] = True
        for nbr in adj[currNode]:
            if not visited[nbr]:
                visited[nbr] = True
                self.dfs(nbr, visited, adj)
    
    # TC : O(V + E)
    # SC : O(V)
    def BFS(self, inDegree, adj):
        q = deque()
        n = len(inDegree)
        topoSort = []

        for i in range(n):
            if inDegree[i] == 0:
                q.append(i)

        while q:
            fNode = q.popleft()
            topoSort.append(fNode)
            for nbr in adj[fNode]:
                inDegree[nbr] -= 1
                if inDegree[nbr] == 0:
                    q.append(nbr)

        return topoSort