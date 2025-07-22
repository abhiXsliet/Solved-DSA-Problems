// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            if (arr[i] < 0 || arr[i] > n || arr[i] == i + 1)
                continue;
            
            while (arr[i] != (i + 1)) {
                if (arr[i] < 0 || arr[i] > n || arr[i] == i + 1 || arr[i] == arr[arr[i] - 1])
                    break;
                    
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        for (int i = 0; i < n; i ++) {
            if (arr[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (n + 1);
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            if (arr[i] > 0 && arr[i] <= n) {
                if (arr[i] != arr[arr[i] - 1]) {
                    swap(arr[i], arr[arr[i] - 1]);
                    i --;
                }
            }
        }
        for (int i = 0; i < n; i ++) {
            if (arr[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (n + 1);
    }
    int missingNumber(vector<int> &arr) {
        // return approach_1(arr);
        return approach_2(arr);
    }
};