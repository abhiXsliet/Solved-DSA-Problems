// https://leetcode.com/problems/range-product-queries-of-powers/




import java.util.*;

class Solution {
    private final int M = 1_000_000_000 + 7;

    // TC : O(Q)
    // SC : O(1)
    public int[] productQueries(int n, int[][] queries) {
        List<Integer> powers = new ArrayList<>();
        for (int i = 0; i <= 31; i ++) {
            if ((n & (1 << i)) != 0) {
                int val = 1 << i; // (int) Math.pow(2, i);
                powers.add(val);
            }
        }    
        
        int q = queries.length;
        int[] result = new int[q];
        for (int i = 0; i < q; i ++) {
            int l = queries[i][0], r = queries[i][1];
            long val = 1;
            for (int j = l; j <= r; j ++) {
                val = (val * powers.get(j)) % M;
            }
            result[i] = (int) val;
        }
        return result;
    }
}