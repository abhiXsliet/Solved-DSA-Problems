// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:  
    // TC : O(M + N)
    // SC : O(1)
    int approach_1(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();
        int i = 0, j = 0, cnt = 0;
        while (i < m && j < n) {
            cnt += 1;
            if (a[i] <= b[j]) {
                if (cnt == k) return a[i];
                i ++;
            } else {
                if (cnt == k) return b[j];
                j ++;
            }
        }
        while (i < m) {
            cnt ++;
            if (cnt == k) return a[i];
            i ++;
        }
        while (j < n) {
            cnt ++;
            if (cnt == k) return b[j];
            j ++;
        }
        return -1;
    }
    
    // TC : O(min(log(M), log(N)))
    // SC : O(1)
    int approach_2(vector<int>& a, vector<int>& b, int k) {
        int m = a.size(), n = b.size();
        if (k > (m + n)) return -1;
        if (m > n) {
            return approach_2(b, a, k);
        }
        
        int low  = max(0, k - n);    // for k = 7, m = 5, n = 4, so min required elements would be max(0, k-n) ie., 3 elements from arr1
        int high = min(k, m);        // for k = 3, m = 5, n = 4, so max required elements would be min(k, m) ie., 3 elements  from arr1       
        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1;
            
            int l1 = mid1 - 1 < 0 ? INT_MIN : a[mid1 - 1];
            int l2 = mid2 - 1 < 0 ? INT_MIN : b[mid2 - 1];
            int r1 = mid1 >= m    ? INT_MAX : a[mid1];
            int r2 = mid2 >= n    ? INT_MAX : b[mid2];
            
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low  = mid1 + 1;
            }
        }
        
        return -1;
    }
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // return approach_1(a, b, k);
        return approach_2(a, b, k);
    }
};