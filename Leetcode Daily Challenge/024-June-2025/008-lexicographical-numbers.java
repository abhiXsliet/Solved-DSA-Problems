// https://leetcode.com/problems/lexicographical-numbers/




import java.util.*;

class Solution {
    // TC : O(N)
    // SC : O(1)
    public List<Integer> lexicalOrder(int n) {
        List<Integer> result = new ArrayList<>();
        for (int i = 1; i <= Math.min(n, 9); i ++) {
            result.add(i);
            solve(i, n, result);
        }
        return result;
    }
    private void solve(int val, int n, List<Integer> result) {
        for (int i = 0; i <= 9; i ++) {
            int nextVal = (val * 10 + i);
            if (nextVal <= n) {
                result.add(nextVal);
                solve(nextVal, n, result);
            } else break;
        }
    }
}