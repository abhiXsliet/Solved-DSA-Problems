// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    int merge(vector<int> &arr, int start, int mid, int end) {
        int n1 = mid - start + 1;
        int n2 = end - mid;
        
        int i = 0, j = 0, k = start, cnt = 0;
        vector<int> left(n1), right(n2);
        
        while (i < n1) {
            left[i] = arr[k];
            i ++, k ++;
        }
        while (j < n2) {
            right[j] = arr[k];
            j ++, k ++;
        }
        
        i = 0, j = 0, k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i ++, k ++;
            } else {
                cnt += (n1 - i);
                arr[k] = right[j];
                j ++, k ++;
            }
        }
        while (i < n1) {
            arr[k] = left[i];
            i ++, k ++;
        }
        while (j < n2) {
            arr[k] = right[j];
            j ++, k ++;
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int start, int end) {
        int cnt = 0;
        if (start >= end) return 0;
        int mid = start + (end - start) / 2;
        cnt += mergeSort(arr, start, mid);
        cnt += mergeSort(arr, mid + 1, end);
        cnt += merge(arr, start, mid, end);
        return cnt;
    }
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};