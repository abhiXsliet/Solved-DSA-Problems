// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/




import java.util.*;

class Solution {
    // TC : O(N^2)
    // SC : O(V+E)
    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;

        Map<Integer, List<Integer>> adj = new HashMap<>();
        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], x -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], x -> new ArrayList<>()).add(edge[0]);
        }

        int[] subTreeXored = new int[n];
        int[] inTime = new int[n];
        int[] outTime = new int[n];
        int[] timer = new int[1];

        dfs(0, -1, subTreeXored, inTime, outTime, timer, nums, adj);

        int result = Integer.MAX_VALUE;
        for (int u = 1; u < n; u ++) {
            for (int v = u + 1; v < n; v ++) {
                
                // xor value of component-1, component-2, component-3
                int xor1 = 0, xor2 = 0, xor3 = 0;

                if (isAncestor(u, v, inTime, outTime)) {
                    xor1 = subTreeXored[v];
                    xor2 = subTreeXored[u] ^ xor1;
                } else if (isAncestor(v, u, inTime, outTime)) {
                    xor1 = subTreeXored[u];
                    xor2 = subTreeXored[v] ^ xor1;
                } else {
                    xor1 = subTreeXored[u];
                    xor2 = subTreeXored[v];
                }

                // xor-of-component-3 = xor-of-total-nodex ^ xor-of-component-1 ^ xor-of-component-2
                xor3 = subTreeXored[0] ^ xor1 ^ xor2;  

                result = Math.min(result, getScore(xor1, xor2, xor3));
            }
        }
        return result;
    }
    private void dfs(int node, int parent, int[] subTreeXored, int[] inTime, int[] outTime, int[] timer, int[] nums, Map<Integer, List<Integer>> adj) {
        subTreeXored[node] = nums[node];
        inTime[node] = timer[0];
        timer[0] += 1;

        for (int nbr : adj.getOrDefault(node, new ArrayList<>())) {
            if (nbr != parent) {
                dfs(nbr, node, subTreeXored, inTime, outTime, timer, nums, adj);
                subTreeXored[node] ^= subTreeXored[nbr];
            }
        }

        outTime[node] = timer[0];
        timer[0] += 1;
    }

    // This function check if node u is an ancestor of node v?
    private boolean isAncestor(int u, int v, int[] inTime, int[] outTime) {
        return (inTime[u] <= inTime[v] && outTime[u] >= outTime[v]);
    }

    private int getScore(int a, int b, int c) {
        int maxXor = Math.max(a, Math.max(b, c));
        int minXor = Math.min(a, Math.min(b, c));

        return (maxXor - minXor);
    }
}