// https://www.geeksforgeeks.org/problems/count-reverse-pairs/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int merge(vector<int> &arr, int start, int mid, int end) {
        int cntRev = 0;
        
        // 1. Counting reverse pair using two pointers
        int p2 = mid + 1;
        for (int p1 = start; p1 <= mid; p1 ++) {
            while (p2 <= end && arr[p1] > 2LL * arr[p2]) p2 ++;
            cntRev += (p2 - (mid + 1));
        }
        
        // 2. Merge two sorted halves
        int n1 = mid - start + 1, n2 = end - mid;
        
        vector<int> left(n1), right(n2);
        
        int i = 0, j = 0, k = start;
        while (i < n1) left[i ++] = arr[k ++];
        
        k = mid + 1;
        while (j < n2) right[j ++] = arr[k ++];
        
        i = 0, j = 0, k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k ++] = left[i ++];
            } else {
                arr[k ++] = right[j ++];
            }
        }
        
        while (i < n1) arr[k ++] =  left[i ++];
        while (j < n2) arr[k ++] = right[j ++];
        
        return cntRev;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int mergeSort(vector<int> &arr, int low, int high) {
        int cntRev = 0;
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        cntRev += mergeSort(arr, low, mid);
        cntRev += mergeSort(arr, mid + 1, high);
        cntRev += merge(arr, low, mid, high);
        return cntRev;
    }
  public:
    int countRevPairs(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};