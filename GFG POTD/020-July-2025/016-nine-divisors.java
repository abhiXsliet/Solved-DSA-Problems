// https://www.geeksforgeeks.org/problems/nine-divisors3751/1




import java.util.*;

class Solution {
    // TC : O(sqrt(N) * log(log(sqrt(N))))
    // SC : O(surt(N))
    public static int countNumbers(int n) {
        int limit = (int)Math.sqrt(n);
        List<Integer> primes = getAllPrimes(limit);
        
        int totalCnt = 0;
        
        // cnt all P^8 <= n where P = prime no.
        for (int i = 0; i < primes.size(); i ++) {
            long val = (long)Math.pow(primes.get(i), 8);
            if (val <= n) totalCnt += 1;
            else break;
        }
        
        // cnt P^2 * Q^2 <= n
        for (int i = 0; i < primes.size(); i ++) {
            for (int j = i + 1; j < primes.size(); j ++) {
                long p = primes.get(i);
                long q = primes.get(j);
                long val = p * p * q * q;
                if (val <= n) totalCnt += 1;
                else break;
            }
        }
        
        return totalCnt;
    }
    
    private static List<Integer> getAllPrimes(int n) {
        List<Integer> primes = new ArrayList<>(Collections.nCopies(n + 1, 1));
        primes.set(0, 0); 
        primes.set(1, 0);
        for (int i = 2; i*i <= n; i ++) {
            for (int j = i*i; j <= n; j += i) {
                if (primes.get(i) == 1) {
                    primes.set(j, 0);
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 2; i <= n; i ++) {
            if (primes.get(i) == 1) {
                result.add(i);
            }
        }
        return result;
    }
}






























































