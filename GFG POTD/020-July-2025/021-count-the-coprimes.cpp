// https://www.geeksforgeeks.org/problems/count-the-coprimes/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N + M*log(M))
    // SC : O(M) where M = max(arr[i])
    int cntCoprime(vector<int>& arr) {
        int maxVal = *max_element(begin(arr), end(arr));
        int size = maxVal + 1;

        // Frequency of each number in the array
        vector<int> freq(size, 0);
        for (int num : arr) freq[num]++;

        // Count of elements divisible by each number d
        vector<int> divisibleCount(size, 0);
        for (int d = 1; d < size; d++) {
            for (int multiple = d; multiple < size; multiple += d) {
                divisibleCount[d] += freq[multiple];
            }
        }

        // dp[d] will store number of pairs (i, j) such that gcd(arr[i], arr[j]) = d
        vector<long long> dp(size, 0);
        for (int d = size - 1; d >= 1; d--) {
            long long count = divisibleCount[d];
            dp[d] = count * (count - 1) / 2;  // Total ways to choose 2 elements divisible by d

            // Remove pairs already counted for multiples of d (inclusion-exclusion)
            for (int multiple = 2 * d; multiple < size; multiple += d) {
                dp[d] -= dp[multiple];
            }
        }

        // dp[1] contains number of coprime pairs (gcd = 1)
        return dp[1];
    }
};