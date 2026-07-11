// https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1/




class Solution {
    private int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int n, m;
    private int maxDist;
    public int longestPath(int[][] mat, int xs, int ys, int xd, int yd) {
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;
        n = mat.length;
        m = mat[0].length;
        maxDist = Integer.MIN_VALUE;
        int[][] vis = new int[n][m];
        solve(mat, vis, xs, ys, xd, yd, 0);
        return maxDist == Integer.MIN_VALUE ? -1 : maxDist;
    }
    
    private void solve(int[][] mat, int[][] vis, int xs, int ys, int xd, int yd, int dist) {
        if (xs == xd && ys == yd) {
            maxDist = Math.max(maxDist, dist);
            return;
        }
        
        vis[xs][ys] = 1;
        
        for (int[] dir : directions) {
            int ns = xs + dir[0];
            int nd = ys + dir[1];
            if (inBound(ns, nd) && vis[ns][nd] == 0 && mat[ns][nd] == 1) {
                solve(mat, vis, ns, nd, xd, yd, dist + 1);
            }
        }
        
        vis[xs][ys] = 0;
    }
    
    private boolean inBound(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
}