// https://www.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsertK(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k)
                return mid;
            else if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // low is the correct insertion position
        return low;
    }
};