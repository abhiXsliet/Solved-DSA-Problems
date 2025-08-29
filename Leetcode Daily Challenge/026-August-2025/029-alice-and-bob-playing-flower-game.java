// https://leetcode.com/problems/alice-and-bob-playing-flower-game/




class Solution {
    public long flowerGame(int n, int m) {
        // return approach_1(n, m);
        return approach_2(n, m);
    }

    // TC : O(1), SC : O(1)
    private long approach_2(int n, int m) {
        return ((long)n * m) / 2;
    }

    // TC : O(1), SC : O(1)
    private long approach_1(int n, int m) {
        long nEven = n / 2;
        long nOdd  = n - nEven;
        
        long mEven = m / 2;
        long mOdd  = m - mEven;

        return (nEven * mOdd) + (nOdd * mEven);
    }
}