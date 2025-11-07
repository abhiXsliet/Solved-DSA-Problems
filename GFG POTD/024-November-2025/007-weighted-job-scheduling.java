// https://www.geeksforgeeks.org/problems/weighted-job-scheduling/1/




import java.util.*;

class Solution {
    private int[] t;
    private int n;
    
    public int maxProfit(int[][] jobs) {
        n = jobs.length;
        
        t = new int[n + 1];
        Arrays.fill(t, -1);
        
        Arrays.sort(jobs, (a, b) -> Integer.compare(a[0], b[0]));
        
        return solve(0, jobs);
    }
    
    private int solve(int i, int[][] jobs) {
        if (i >= n) return 0;
        if (t[i] != -1) return t[i];
        
        int nxtI = lowerBound(jobs, i + 1, jobs[i][1]);
        
        int take = jobs[i][2] + solve(nxtI, jobs);
        int skip = solve(i + 1, jobs);
        
        return t[i] = Math.max(take, skip);
    }
    
    private int lowerBound(int[][] jobs, int low, int curr_job_end) {
        int high = n - 1;
        int res  = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid][0] >= curr_job_end) {
                res  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return res;
    }
}