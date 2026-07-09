// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/




class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int[] component = new int[n];
        int compNum = 0;
        component[0] = compNum;

        for (int i = 1; i < n; i ++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                compNum += 1;
            }
            component[i] = compNum;
        }

        int q = queries.length;
        boolean[] result = new boolean[q];
        for (int i = 0; i < q; i ++) {
            int u = queries[i][0], v = queries[i][1];
            result[i] = (component[u] == component[v]) ? true : false;
        }
        return result;
    }
}