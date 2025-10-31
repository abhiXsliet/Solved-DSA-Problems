// https://www.geeksforgeeks.org/problems/shortest-cycle/1/




import java.util.*;

class Solution {
    public int shortCycle(int V, int[][] edges) {
        // Step 1: Create adjacency list
        Map<Integer, ArrayList<Integer>> adj = prepareAdj(V, edges);

        int ans = Integer.MAX_VALUE;

        // Step 2: Try BFS from every vertex
        for (int i = 0; i < V; i++) {
            ans = Math.min(ans, bfs(i, V, adj));
        }

        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }

    // BFS from a single source to find shortest cycle
    private int bfs(int src, int V, Map<Integer, ArrayList<Integer>> adj) {
        int[] dist = new int[V];
        Arrays.fill(dist, -1);
        Queue<Integer> q = new LinkedList<>();

        dist[src] = 0;
        q.offer(src);

        int shortest = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            int u = q.poll();

            for (int v : adj.getOrDefault(u, new ArrayList<>())) {
                if (dist[v] == -1) { 
                    // not visited yet
                    dist[v] = dist[u] + 1;
                    q.offer(v);
                } else if (dist[v] >= dist[u]) {
                    // visited but not parent (cycle found)
                    shortest = Math.min(shortest, dist[v] + dist[u] + 1);
                }
            }
        }

        return shortest;
    }

    // Helper to build adjacency list
    private Map<Integer, ArrayList<Integer>> prepareAdj(int V, int[][] edges) {
        Map<Integer, ArrayList<Integer>> adj = new HashMap<>();

        for (int[] e : edges) {
            adj.computeIfAbsent(e[0], k -> new ArrayList<>()).add(e[1]);
            adj.computeIfAbsent(e[1], k -> new ArrayList<>()).add(e[0]);
        }

        return adj;
    }
}