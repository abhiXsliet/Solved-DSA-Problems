// https://leetcode.com/problems/sort-matrix-by-diagonals/




import java.util.*;

class Solution {
    private int m, n;

    public int[][] sortMatrix(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // return approach_1(grid);
        return approach_2(grid);
    }

    // TC : O(M * N)
    // SC : O(K) where K = max-length of diagonal
    private int[][] approach_2(int[][] grid) {
        for (int i = 0; i < m; i ++) {
            sortDiagonal(i, 0, grid, true);
        }
        for (int j = 1; j < n; j ++) {
            sortDiagonal(0, j, grid, false);
        }
        return grid;
    }

    void sortDiagonal(int r, int c, int[][] grid, boolean isLowerDiag) {
        List<Integer> diagonal = new ArrayList<>();
        int i = r, j = c;

        while (i < m && j < n) {
            diagonal.add(grid[i][j]);
            i ++;
            j ++;
        }

        if (isLowerDiag) {
            diagonal.sort(Collections.reverseOrder());
        } else {
            Collections.sort(diagonal);
        }

        i = r;
        j = c;
        for (int idx = 0; idx < diagonal.size(); idx ++) {
            grid[i ++][j ++] = diagonal.get(idx);
        }
    }

    // TC : O((M * N) + (K*log(K))) Where K = No. of diagonals
    // SC : O(M * N)
    private int[][] approach_1(int[][] grid) {
        Map<Integer, List<Integer>> mpp = new HashMap<>();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int key = (i - j);
                mpp.putIfAbsent(key, new ArrayList<>());
                mpp.get(key).add(grid[i][j]);
            }
        }

        for (Map.Entry<Integer, List<Integer>> entry : mpp.entrySet()) {
            if (entry.getKey() >= 0) {
                Collections.sort(entry.getValue());
            } else {
                entry.getValue().sort(Collections.reverseOrder());
            }
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                List<Integer> list = mpp.get(i - j);
                grid[i][j] = list.get(list.size() - 1);
                list.remove(list.size() - 1);
            }
        }
        return grid;
    }
}