// https://www.geeksforgeeks.org/problems/count-the-paths4332/1




import java.util.*;

class Solution {
    public int countPaths(int[][] edges, int V, int src, int dest) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[V];
        
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v] ++;
        }
        
        // Map<Integer, Integer> memo = new HashMap<>();
        // return dfs(adj, src, dest, memo);
        
        return bfs(adj, src, dest, indegree);
    }
    int bfs(Map<Integer, List<Integer>> adj, int src, int dest, int[] indegree) {
        int V = indegree.length;
        int[] ways = new int[V];
        Queue<Integer> q = new LinkedList<>();
        ways[src] = 1;
        
        for (int i = 0; i < V; i ++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.getOrDefault(u, new ArrayList<>())) {
                ways[v] += ways[u];
                indegree[v] --;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }
        return ways[dest];
    }
    int dfs(Map<Integer, List<Integer>> adj, int src, int dest, Map<Integer, Integer> memo) {
        if (src == dest) return 1;
        if (memo.containsKey(src)) return memo.get(src);
        int ways = 0;
        for (int nbr : adj.getOrDefault(src, new ArrayList<>())) {
            ways += dfs(adj, nbr, dest, memo);
        }
        memo.put(src, ways);
        return ways;
    }
}