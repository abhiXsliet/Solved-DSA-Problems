// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/




import java.util.*;

class Solution {
    private int n;

    // TC : O(N * K * log(N))
    // SC : O(N * K)
    public int maxValue(int[][] events, int k) {
        n = events.length;

        Arrays.sort(events, (a, b) -> {
            if (a[0] == b[0]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        long[][] dp = new long[n + 1][k + 1];
        for (long[] row : dp) {
            Arrays.fill(row, -1);
        }

        return (int)solve(events, k, 0, dp);
    }

    private long solve(int[][] events, int k, int i, long[][] dp) {
        if (i >= n || k <= 0) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        int nextValidIdx = binarySearch(events, i, events[i][1]);

        long take = events[i][2] + solve(events, k - 1, nextValidIdx, dp);
        long notT = solve(events, k, i + 1, dp);

        return dp[i][k] = Math.max(take, notT);
    }

    private int binarySearch(int[][] events, int low, int tar) {
        int high = n - 1;
        int ans  = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > tar) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}