// https://www.geeksforgeeks.org/problems/count-the-coprimes/1




import java.util.*;

class Solution {
    // TC : O(N + M*log(M))
    // SC : O(M) where M = max(arr[i])
    int cntCoprime(int[] arr) {
        int maxi = Arrays.stream(arr).max().getAsInt();

        int[] freq = new int[maxi + 1];
        for (int num : arr) freq[num] ++;
        
        // count the nos which are divisible by d
        int[] cntDivisibleByD = new int[maxi + 1];
        for (int d = 1; d <= maxi; d ++) {
            for (int mul = d; mul <= maxi; mul += d) {
                cntDivisibleByD[d] += freq[mul];
            }
        }
        
        // dp[d] stores the no of pairs(i, j) such that gcd(arr[i], arr[j]) == 1
        long[] dp = new long[maxi + 1];
        for (int d = maxi; d >= 1; d --) {
            long c = cntDivisibleByD[d];
            dp[d]  = (c * (c - 1)) / 2;   // Total ways to choose 2 elements divisible by d
            
            // Remove overcounted pairs using inclusion-exclusion
            for (int mul = 2*d; mul <= maxi; mul += d) {
                dp[d] -= dp[mul];
            }
        }
        
        // dp[1] contains the number of coprime pairs (gcd = 1)
        return (int)dp[1]; 
    }
}