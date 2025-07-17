// https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1




import java.util.*;

class Solution {
    // TC : O(sqrt(k) + m*log(n))
    // SC : O(sqrt(k))
    public int maxKPower(int n, int k) {
        Map<Integer, Integer> primeFactorsK = getAllPrimeFactor(k);
        int result = Integer.MAX_VALUE;
        for (Map.Entry<Integer, Integer> it : primeFactorsK.entrySet()) {
            int primeFactor    = it.getKey();
            int primeFactorCnt = it.getValue();
            
            int occurances = cntPrimePInN(n, primeFactor);

            result = Math.min(result, occurances / primeFactorCnt);
        }
        return result;
    }
    
    private int cntPrimePInN(int n, int p) {
        int count = 0;
        while (n > 0) {
            n /= p;
            count += n;
        }
        return count;
    }
    
    private Map<Integer, Integer> getAllPrimeFactor(int k) {
        Map<Integer, Integer> pf = new HashMap<>();
        for (int i = 2; i * i <= k; i ++) {
            while (k % i == 0) {
                pf.put(i, pf.getOrDefault(i, 0) + 1);
                k /= i;
            }
        }
        if (k > 1) pf.put(k, pf.getOrDefault(k, 0) + 1);
        return pf;
    }
}