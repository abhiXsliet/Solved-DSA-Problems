// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/



import java.util.*;

class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        // return approach_1(n, edges); // Mark 'u' as an ancestor and traverse adjacent nodes to update their ancestors as node 'u'

        // return approach_2(n, edges); //Reverse the graph: For each node 'u', traverse its adjacent nodes to identify which nodes consider 'u' as an ancestor, marking these nodes as true during the traversal.

        return approach_3(n, edges);    // Get Topological Sort, then find their ancestor of ancestor nodes
    }

    // TC : O(V^2 + (V+E) + Vlog(V)) -> O(V+E) for building the graph and performing the topological sort, 
    //                               -> O(V^2) for processing each node and merging ancestor lists.
    //                               -> O(VlogV) for sorting the ancestor lists for each node.
    // SC : O(V^2 + E)    
    private static List<List<Integer>> approach_3(int n, int[][] edges) {
        int[] inDegree = new int[n];
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {  // O(V + E)
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k->new ArrayList<>()).add(v);
            inDegree[v] ++;
        }

        // Find TopoSort and find its ancestor of ancestor nodes
        List<Integer> topoSort = BFS(inDegree, adj);    // kahn's algorithm

        // To find ancestor of ancestors : use List<Set<Integer>>
        List<Set<Integer>> vec = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            vec.add(new HashSet<>());
        }

        for (int node : topoSort) {
            for (int v : adj.getOrDefault(node, new ArrayList<>())) {
                vec.get(v).add(node);   // add node as ancestor of v
                vec.get(v).addAll(vec.get(node));   // add ancestors of node
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            List<Integer> ancestor = new ArrayList<>(vec.get(i));
            Collections.sort(ancestor);
            result.add(ancestor);
        }

        return result;
    }

    // TC : O(V*(V + E))
    // SC : O(V + E)
    private static List<List<Integer>> approach_2(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {  // O(V + E)
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(v, k->new ArrayList<>()).add(u);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            result.add(new ArrayList<>());
        }

        for (int u = 0; u < n; u ++) {  // O(V)
            List<Integer> ancestor = new ArrayList<>();
            boolean[] visited = new boolean[n];
            dfs(u, visited, adj);  // O(V + E)

            for (int i = 0; i < n; i ++) {
                if (i == u) continue;

                if (visited[i] == true) { // node 'i' traverse and marked true means node 'u' was its ancestor
                    ancestor.add(i);
                }
            }
            result.set(u, ancestor);
        }

        return result;
    }

    // TC : O(V*(V + E))
    // SC : O(V + E)
    private static List<List<Integer>> approach_1(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {  // O(V + E)
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k->new ArrayList<>()).add(v);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            result.add(new ArrayList<>());
        }

        for (int u = 0; u < n; u ++) {  // O(V)
            int ancestor = u;
            DFS(u, ancestor, adj, result);  // O(V + E)
        }

        return result;
    }

    // TC : O(V + E)
    // SC : O(V + E) : Recursive Depth
    private static void DFS(int currNode, int ancestor, Map<Integer, List<Integer>> adj, List<List<Integer>> result) {
        
        for (int nbr : adj.getOrDefault(currNode, new ArrayList<>())) {
            if (result.get(nbr).isEmpty() || result.get(nbr).get(result.get(nbr).size() - 1) != ancestor) { // to avoid duplicacy
                result.get(nbr).add(ancestor);
                DFS(nbr, ancestor, adj, result);
            }
        }
    }

    // TC : O(V + E)
    // SC : O(V + E) : Recursive Depth
    private static void dfs(int currNode, boolean[] visited, Map<Integer, List<Integer>> adj) {
        visited[currNode] = true;
        for (int nbr : adj.getOrDefault(currNode, new ArrayList<>())) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                dfs(nbr, visited, adj);
            }
        }
    }

    // TC : O(V + E)
    // SC : O(V)
    private static List<Integer> BFS(int[] inDegree, Map<Integer, List<Integer>> adj) {
        Queue<Integer> q = new LinkedList<>();
        int n = inDegree.length;
        List<Integer> topoSort = new ArrayList<>();

        for (int i = 0; i < n; i ++) {
            if (inDegree[i] == 0) {
                q.offer(i);
            }
        }

        while(!q.isEmpty()) {
            int fNode = q.poll();
            topoSort.add(fNode);
            for (int nbr : adj.getOrDefault(fNode, new ArrayList<>())) {
                inDegree[nbr] --;
                if (inDegree[nbr] == 0) {
                    q.offer(nbr);
                }
            }
        }
        return topoSort;
    }
}