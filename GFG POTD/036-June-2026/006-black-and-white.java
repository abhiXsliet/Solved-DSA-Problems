// https://www.geeksforgeeks.org/problems/black-and-white-1587115620/1/




class Solution {
    public long numOfWays(int n, int m) {
        long N = 1L * n * m;

        // Total ordered placements of black and white knights
        long totalPairs = N * (N - 1);

        // Total attacking ordered pairs
        long attackingPairs = 4L * (n - 1) * (m - 2)
                            + 4L * (n - 2) * (m - 1);

        return totalPairs - attackingPairs;
    }
}