// https://www.geeksforgeeks.org/problems/smallest-divisor/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int getSummationDiv(vector<int> &arr, int n, int div) {
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] % div) sum += 1;
            sum += (arr[i] / div);
        }
        return sum;
    }
  public:
    // TC : O(N * max(arr[i]))
    // SC : O(1)
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 1, high = *max_element(begin(arr), end(arr));
        int ans = INT_MIN;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getSummationDiv(arr, n, mid) <= k) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (ans == INT_MIN) ? -1 : ans;
    }
};