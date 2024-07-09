// https://leetcode.com/problems/average-waiting-time/



class Solution {
    // TC : O(N)
    // SC : O(1)
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;

        double totalWaitTime = 0;
        int currTime         = 0;

        for(int[] vec : customers) {
            int arrivalTime = vec[0];
            int cookTime    = vec[1];

            if(currTime < arrivalTime) {
                currTime = arrivalTime;
            }

            int waitTime   = currTime + cookTime - arrivalTime;
            totalWaitTime += waitTime;
            currTime      += cookTime;
        }

        return totalWaitTime/n;
    }
}