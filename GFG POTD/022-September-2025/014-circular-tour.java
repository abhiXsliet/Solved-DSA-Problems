// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1/




import java.util.*;

class Solution {
    public int startStation(int[] gas, int[] cost) {
        // return approach_1(gas, cost);
        return approach_2(gas, cost);    // one pass
    }
    
    // TC : O(N)
    // SC : O(1)
    private static int approach_2(int[] gas, int[] cost) {
        int n = gas.length;
        int deficit = 0, curr_bal = 0, startPt = 0;
        for (int i = 0; i < n; i ++) {
            curr_bal += (gas[i] - cost[i]);
            if (curr_bal < 0) {
                deficit += curr_bal;
                curr_bal = 0;
                startPt  = i + 1;
            }
        }
        return (deficit + curr_bal >= 0) ? startPt : -1;
    }
    
    // TC : O(N)
    // SC : O(1)
    private static int approach_1(int[] gas, int[] cost) {
        int n = gas.length;
        int balance = 0;
        for (int i = 0; i < n; i ++) {
            balance += (gas[i] - cost[i]);
        }
        
        if (balance < 0) return -1;
        
        int curr_bal = 0, startPt = 0;
        for (int i = 0; i < n; i ++) {
            curr_bal += (gas[i] - cost[i]);
            if (curr_bal < 0) {
                curr_bal = 0;
                startPt  = i + 1;
            }
        }
        return startPt;
    }
}