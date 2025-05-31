// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/




import java.util.*;

class Solution {
    // TC : O(V + E)
    // SC : O(V + E)
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();

        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[n];

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            indegree[v] ++;
        }

        Queue<Integer> q = new LinkedList<>();
        int[][] dp = new int[n][26];

        for (int i = 0; i < n; i ++) {
            if (indegree[i] == 0) {
                q.offer(i);
                dp[i][colors.charAt(i) - 'a'] = 1;
            }
        }

        int largestColorVal = 0;
        int countNodes = 0;

        while (!q.isEmpty()) {
            int u = q.poll();

            countNodes += 1;
            largestColorVal = Math.max(largestColorVal, dp[u][colors.charAt(u) - 'a']);

            List<Integer> neighbours = adj.getOrDefault(u, new ArrayList<>());
            
            for (int v : neighbours) {
                for (int i = 0; i < 26; i ++) {
                    int inc = (colors.charAt(u) - 'a' == i) ? 1 : 0;
                    dp[v][i] = Math.max(dp[v][i], dp[u][i] + inc);
                }

                indegree[v] --;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }
        
        return (countNodes < n) ? -1 : largestColorVal;
    }
}