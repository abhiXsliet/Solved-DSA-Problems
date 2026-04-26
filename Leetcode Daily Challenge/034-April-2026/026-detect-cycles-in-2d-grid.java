// https://leetcode.com/problems/detect-cycles-in-2d-grid/




import java.util.*;

class Tuple {
    int a, b, c, d;
    Tuple(int a, int b, int c, int d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
}

class Solution {
    int m, n;
    int[][] directions = new int[][]{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    private boolean dfs(int i, int j, int parentI, int parentJ, boolean[][] visited, char[][] grid) {
        if (visited[i][j]) return true;

        visited[i][j] = true;

        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i][j] == grid[i_][j_]) {
                if (i_ == parentI && j_ == parentJ) continue;

                if (dfs(i_, j_, i, j, visited, grid))
                    return true;
            }
        }
       

        return false;
    }

    private boolean bfs(int i, int j, boolean[][] visited, char[][] grid) {
        Queue<Tuple> q = new ArrayDeque<>();
        q.offer(new Tuple(i, j, i, j));
        visited[i][j] = true;

        while (!q.isEmpty()) {
            Tuple curr = q.poll();
            i = curr.a;
            j = curr.b;
            int parentI = curr.c;
            int parentJ = curr.d;

            for (int[] dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i][j] == grid[i_][j_]) {
                    
                    if (i_ == parentI && j_ == parentJ) continue;

                    if (visited[i_][j_] == true) 
                        return true;

                    visited[i_][j_] = true;

                    q.offer(new Tuple(i_, j_, i, j));
                }
            }
        }

        return false;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    public boolean approach_1(char[][] grid) {
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, i, j, visited, grid)) 
                        return true;
                }
            }
        }

        return false;
    }

    // TC : O(M * N)
    // SC : O(M * N)
    public boolean approach_2(char[][] grid) {
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!visited[i][j]) {
                    if (bfs(i, j, visited, grid)) 
                        return true;
                }
            }
        }

        return false;
    }

    public boolean containsCycle(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        // return approach_1(grid);
        return approach_2(grid);
    }
}