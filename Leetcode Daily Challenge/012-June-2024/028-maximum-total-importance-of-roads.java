// https://leetcode.com/problems/maximum-total-importance-of-roads/



import java.util.*;

class Solution {
    public long maximumImportance(int n, int[][] roads) {
        // return approach_1(n, roads);

        return approach_2(n, roads);
    }

    // TC : O(N*log(N))
    // SC : O(N)
    private static long approach_1(int n, int[][] roads) {
        int[] inDegree = new int[n];
        for (int[] road : roads) {
            int a = road[0];
            int b = road[1];
            inDegree[a] ++;
            inDegree[b] ++;
        }
        
        List<int[]> store = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            store.add(new int[]{inDegree[i], i});
        }

        // sorting based on the highest indegree of roads
        store.sort((a, b) -> Integer.compare(b[0], a[0]));
        
        int values = n;
        
        // Assigning value based on highest indegree of roads
        for (int i = 0; i < n; i ++) {
            int idx       = store.get(i)[1]; // index of highest indegree of road
            inDegree[idx] = values --;
        }

        long importance = 0;
        for (int[] road : roads) {
            importance += inDegree[road[0]];
            importance += inDegree[road[1]];
        }
        return importance;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    private static long approach_2(int n, int[][] roads) {
        int[] inDegree = new int[n];
        for (int[] road : roads) {
            int a = road[0];
            int b = road[1];
            inDegree[a] ++;
            inDegree[b] ++;
        }
       
        // sorting based on the highest indegree of roads
        Arrays.sort(inDegree);

        long importance = 0;
        for (int val = 1; val <= n; val ++) {
            importance += (long)inDegree[val - 1] * val;
        }
        return importance;
    }
}