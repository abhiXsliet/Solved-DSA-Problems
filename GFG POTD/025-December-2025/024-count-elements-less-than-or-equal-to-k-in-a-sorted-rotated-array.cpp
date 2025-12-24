// https://www.geeksforgeeks.org/problems/count-elements-less-than-or-equal-to-k-in-a-sorted-rotated-array/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getPivot(vector<int>& arr, int n) {
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
  public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int pivot = getPivot(arr, n);

        int count = 0;
        if (x >= arr[pivot]) {
            count += upper_bound(begin(arr) + pivot, end(arr), x) - (begin(arr) + pivot);
        }
        
        if (pivot > 0 && x >= arr[0]) {
            count += upper_bound(begin(arr), begin(arr) + pivot, x) - begin(arr);
        }
        
        return count;
    }
};