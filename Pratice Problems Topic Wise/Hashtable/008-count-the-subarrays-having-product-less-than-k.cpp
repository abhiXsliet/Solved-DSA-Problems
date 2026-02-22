// https://www.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        long result = 0, product = 1;
        int i = 0, j = 0;
        while (j < n) {
            product *= arr[j];
            while (i <= j && product >= k) { // catch : i <= j
                product /= arr[i];
                i ++;
            }
            result += (j - i + 1);
            j ++;
        }
        return result;
    }
};