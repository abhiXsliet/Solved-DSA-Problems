// https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // Greedily check if we can pick k elements such that each is at least 'tar' apart from the last picked
    bool isPossible(vector<int> &arr, int k, int tar) {
        int prev = arr.front(), count = 1;
        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i] >= prev + tar) {
                count += 1;
                prev = arr[i];
            }
        }
        return count >= k;
    }
  public:
    // TC : O(N * log(N))
    // SC : O(1)
    int maxMinDiff(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        int low = 0, high = arr.back() - arr.front(), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};