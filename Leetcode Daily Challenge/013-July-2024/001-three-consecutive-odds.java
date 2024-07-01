// https://leetcode.com/problems/three-consecutive-odds/



class Solution {
    // TC : O(N)
    // SC : O(1)
    public boolean threeConsecutiveOdds(int[] arr) {
        for (int i = 0; i + 2 < arr.length; i ++) {
            if ((arr[i]     & 1) == 1 && 
                (arr[i + 1] & 1) == 1 && 
                (arr[i + 2] & 1) == 1) {
                return true;
            }
        }
        return false;
    }
}