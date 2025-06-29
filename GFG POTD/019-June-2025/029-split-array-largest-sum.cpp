// https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool isPossibleSplit(vector<int> &arr, int tar, int k) {
        int countSplit = 1;
        int sumOfSplit = 0;
        for (int &num : arr) {
            if(sumOfSplit + num <= tar) {
                sumOfSplit += num;
            } else {
                countSplit += 1;
                sumOfSplit  = num;
            }
        }
        return countSplit <= k;
    }
  public:
    // TC : O(N * log(Sum of elements in arr))
    // SC : O(1)
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        
        int low = 0, high = 0;
        for (int &num : arr) {
            low = max(low, num);
            high += num;
        }
        
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleSplit(arr, mid, k)) {
                ans  = mid;
                high = mid - 1;
            } else {
                low  = mid + 1;
            }
        }
        return ans;
    }
};