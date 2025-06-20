// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int maxDistance(String s, int k) {
        int n = s.length();

        int cntN = 0, cntS = 0, cntE = 0, cntW = 0;
        int maxD = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i ++) {
            if (s.charAt(i) == 'N') {
                cntN += 1;
            } else if (s.charAt(i) == 'S') {
                cntS += 1;
            } else if (s.charAt(i) == 'E') {
                cntE += 1;
            } else {
                cntW += 1;
            }
            
            int stepsTillNow = (i + 1);
            int actualDist   = Math.abs(cntE - cntW) + Math.abs(cntN - cntS);
            int wastedSteps  = stepsTillNow - actualDist;

            int extraDist = 0;
            if (actualDist != stepsTillNow) {
                extraDist = Math.min(2*k, wastedSteps);
            } 
                
            maxD = Math.max(maxD, actualDist + extraDist);
        }

        return maxD;
    }
}