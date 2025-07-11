// https://www.geeksforgeeks.org/problems/trail-of-ones3242/1




class Solution {
    // TC : O(N)
    // SC : O(1)
    public int countConsec(int n) {
        int prev1 = 0, prev2 = 1;
        int ans   = 1;
        for (int i = 3; i <= n; i ++) {
            int sum = prev1 + prev2;

            ans = (2 * ans) + sum;
            
            prev1 = prev2;
            prev2 = sum;
        }
        return ans;
    }
}