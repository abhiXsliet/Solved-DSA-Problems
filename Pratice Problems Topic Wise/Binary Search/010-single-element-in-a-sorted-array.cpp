// https://leetcode.com/problems/single-element-in-a-sorted-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(N))
    // SC : O(1)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid - 1 >= 0 && mid + 1 < n && arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
                return arr[mid];
            } else {
                int lCnt = mid  - low;
                int rCnt = high - mid;

                if (lCnt == rCnt && lCnt == 1) {
                    if (mid - 1 >= 0 && mid + 1 < n && arr[mid] == arr[mid - 1]) 
                        return arr[mid + 1];
                    else if (mid - 1 >= 0) 
                        return arr[mid - 1];
                } 
                if (lCnt % 2 == 0) {
                    if (mid - 1 >= 0 && mid + 1 < n && arr[mid] == arr[mid - 1]) {
                        high = mid - 2;
                    } else {
                        low = mid + 2;
                    }
                } else {
                    if (mid - 1 >= 0 && mid + 1 < n && arr[mid] == arr[mid - 1]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }
        return -1;
    }

    // TC : O(log(N))
    // SC : O(1)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            bool isEven = (mid - low) % 2 == 0;

            if (arr[mid] == arr[mid - 1]) {
                if (isEven) {
                    high = mid - 2;
                } else {
                    low  = mid + 1;
                }
            } else if (arr[mid] == arr[mid + 1]) {
                if (isEven) {
                    low  = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else {
                return arr[mid];
            }
        }
        return arr[low];
    }
public:
    int singleNonDuplicate(vector<int>& arr) {
        // return approach_1(arr);  
        return approach_2(arr);
    }
};