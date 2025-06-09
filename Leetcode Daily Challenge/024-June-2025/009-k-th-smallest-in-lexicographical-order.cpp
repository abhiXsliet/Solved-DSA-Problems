// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(n))
    int getCountPrefixes(long curr, long next, long n) {
        int countNum = 0;
        while (curr <= n) {
            countNum += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, n + 1);
        }
        return countNum;
    }
public:
    // TC : O(log(n) * log(n))
    // SC : O(1)
    int findKthNumber(int n, int k) {
        int curr = 1; 
        k -= 1;  
        while (k > 0) {
            int countNum = getCountPrefixes(curr, curr + 1, n);
            if (countNum <= k) {
                k -= countNum;
                curr += 1;
            } else {
                k -= 1;
                curr *= 10;
            }
        }
        return curr;
    }
};