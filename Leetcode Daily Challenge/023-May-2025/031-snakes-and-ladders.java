// https://leetcode.com/problems/snakes-and-ladders/




import java.util.*;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;

        Queue<Integer> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][n];
        q.offer(1);
        visited[n - 1][0] = true;
        int steps = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            while (size -- > 0) {
                int fVal = q.poll();
                
                if (fVal == n * n) return steps;

                for (int i = 1; i <= 6; i ++) {
                    int newVal = (fVal + i);

                    if (newVal > n * n) break;

                    int[] coor = getCoordinates(newVal, n);
                    int r = coor[0];
                    int c = coor[1];

                    if (visited[r][c] == true) continue;

                    visited[r][c] = true;

                    if (board[r][c] == -1) {
                        q.offer(newVal);
                    } else {
                        q.offer(board[r][c]);
                    }
                }
            }
            steps ++;
        }
        return -1;
    }
    private int[] getCoordinates(int val, int n) {
        int topR = (val - 1) / n;
        int botR = (n - 1) - topR;

        int col = (val - 1) % n;
        
        if ((n % 2 == 1 && botR % 2 == 1) || (n % 2 == 0 && botR % 2 == 0)) {
            col = (n - 1) - col;
        }

        return new int[]{botR, col};
    }
}