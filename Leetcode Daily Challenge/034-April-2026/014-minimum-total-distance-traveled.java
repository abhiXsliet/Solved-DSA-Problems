// https://leetcode.com/problems/minimum-total-distance-traveled/




import java.util.*;

class Solution {
    private long mem(List<Integer> robot, List<Integer> position, int i, int j, long[][] dp) {
        if (i >= robot.size()) return 0;
        if (j >= position.size()) return (long)1e12;

        if (dp[i][j] != -1) return dp[i][j];

        long take = Math.abs(robot.get(i) - position.get(j)) + mem(robot, position, i + 1, j + 1, dp);
        long skip = mem(robot, position, i, j + 1, dp);

        return dp[i][j] = Math.min(take, skip);
    }

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        int n = robot.size();

        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[1], b[1]);
        });

        List<Integer> position = new ArrayList<>();
        for (int[] f : factory) {
            int pos = f[0];
            int lim = f[1];
            for (int j = 0; j < lim; j ++) {
                position.add(pos);
            }
        }

        int m = position.size();
        long[][] dp = new long[n + 1][m + 1];
        for (int i = 0; i <= n; i ++) {
            Arrays.fill(dp[i], -1);
        }

        return mem(robot, position, 0, 0, dp);
    }
}