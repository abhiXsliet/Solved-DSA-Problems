// https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1




class Solution {
    public int maxRectSum(int mat[][]) {
        return optimal(mat);
    }
    
    // TC : O(M^2 * N)
    // SC : O(N)
    private int optimal(int mat[][]) {
        int n = mat.length, m = mat[0].length;
        
        int maxSubMatSum = Integer.MIN_VALUE;
        
        for (int left = 0; left < m; left ++) {
            
            int[] temp = new int[n];
            
            for (int right = left; right < m; right ++) {
                
                for (int i = 0; i < n; i ++) {
                    temp[i] += mat[i][right];
                }
                
                maxSubMatSum = Math.max(maxSubMatSum, kadanes(temp));
            }
        }
        
        return maxSubMatSum;
    }
    
    private int kadanes(int[] arr) {
        int prev = 0, maxSum = Integer.MIN_VALUE;
        for (int num : arr) {
            prev   = Math.max(num, prev + num);
            maxSum = Math.max(maxSum, prev);
        }
        return maxSum;
    }
};