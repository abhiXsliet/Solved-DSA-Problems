// https://leetcode.com/problems/diagonal-traverse/




import java.util.*;

class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        // return approach_1(mat);
        return approach_2(mat);
    }

    // TC : O(M * N)
    // SC : O(1)
    private int[] approach_2(int[][] mat) {
        int m = mat.length, n = mat[0].length;

        int i = 0, j = 0, idx = 0;
        int[] result = new int[m * n];
        boolean flip = true;

        while (i < m && j < n) {
            if (flip) {
                while (i >= 0 && j < n) {
                    result[idx ++] = mat[i][j];
                    i --;
                    j ++;
                }
                if (j == n) {
                    i += 2;
                    j -= 1;
                } else {
                    i += 1;
                }
            } else {
                while (i < m && j >= 0) {
                    result[idx ++] = mat[i][j];
                    i ++;
                    j --;
                }
                if (i == m) {
                    i -= 1;
                    j += 2;
                } else {
                    j += 1;
                }
            }

            flip = !flip;
        }

        return result;
    }

    // TC : O(M*N*log(M*N))
    // SC : O(M*N)
    private int[] approach_1(int[][] mat) {
        int m = mat.length, n = mat[0].length;

        Map<Integer, List<Integer>> mpp = new TreeMap<>();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mpp.computeIfAbsent((i + j), k -> new ArrayList<>()).add(mat[i][j]);
            }
        }

        int[] result = new int[m * n];
        int idx = 0;

        for (Map.Entry<Integer, List<Integer>> entry : mpp.entrySet()) {
            List<Integer> value = entry.getValue();

            if (entry.getKey() % 2 == 0) {
                Collections.reverse(value);
            }

            for (int val : value) {
                result[idx ++] = val;
            }
        }

        return result;
    }
}