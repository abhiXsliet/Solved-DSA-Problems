// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/




import java.util.*;

class Solution {
    static class Pair {
        int node;
        int weight;
        Pair(int weight, int node) {
            this.weight = weight;
            this.node = node;
        }
    }

    public int minCost(int n, int[][] edges) {
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj.get(u).add(new Pair(w, v));
            adj.get(v).add(new Pair(2*w, u));
        }

        int[] result = new int[n];
        Arrays.fill(result, Integer.MAX_VALUE);

        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.weight, b.weight)
        );

        result[0] = 0;
        pq.offer(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int dist  = curr.weight;
            int fNode = curr.node;

            if (fNode == n - 1) return result[n - 1];

            for (Pair nbr : adj.get(fNode)) {
                int nbrDist = nbr.weight;
                int nbrNode = nbr.node;

                if (dist + nbrDist < result[nbrNode]) {
                    result[nbrNode] = dist + nbrDist;
                    pq.offer(new Pair(result[nbrNode], nbrNode));
                }
            }
        }

        return -1;
    }
}