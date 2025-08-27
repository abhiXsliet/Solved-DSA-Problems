// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxRectArea = 0;
        double maxDiagArea = 0.0;

        for (int[] dim : dimensions) {
            double diagArea = Math.sqrt((dim[0] * dim[0]) + (dim[1] * dim[1]));
            int area = (dim[0] * dim[1]);

            if (diagArea > maxDiagArea) {
                maxDiagArea = diagArea;
                maxRectArea = area;
            } else if (diagArea == maxDiagArea) {
                maxRectArea = Math.max(maxRectArea, area);
            }
        } 

        return maxRectArea;
    }
}