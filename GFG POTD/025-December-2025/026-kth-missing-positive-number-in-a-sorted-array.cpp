// https://www.geeksforgeeks.org/problems/kth-missing-positive-number-in-a-sorted-array/1/




#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    int brute(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        unordered_set<int> st(begin(arr), end(arr));
        for (int i = 1; i <= arr[n - 1] + k; i ++) {
            if (!st.count(i)) {
                cnt ++;
                if (cnt == k) {
                    return i;
                }
            }
        }
        return -1;
    }
    
    // TC : O(N)
    // SC : O(1)
    int better(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (num != arr[i]) {
                cnt ++;
                i --;
                if (cnt == k) return num;
            } 
            num ++;
        }
        return num + (k - cnt) - 1;
    }
    
    // TC : O(log(N))
    // SC : O(1)
    int optimal(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing_nos = arr[mid] - (mid + 1);
            if (missing_nos < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
  public:
    int kthMissing(vector<int> &arr, int k) {
        // return brute(arr, k);
        
        // return better(arr, k);
        
        return optimal(arr, k);
    }
};