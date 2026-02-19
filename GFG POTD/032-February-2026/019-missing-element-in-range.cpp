// https://www.geeksforgeeks.org/problems/missing-element-in-range/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_1(vector<int> &arr, int low, int high) {
        unordered_set<int> st(begin(arr), end(arr));
        vector<int> result;
        for (int i = low; i <= high; i ++) {
            if (!st.count(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> approach_2(vector<int> &arr, int low, int high) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        int idx = lower_bound(begin(arr), end(arr), low) - begin(arr);
        
        vector<int> result;
        int i = idx, x = low;
        
        while (i < n && x <= high) {
            if (x != arr[i]) {
                result.push_back(x);
            } else {
                i ++;
                while (arr[i] == arr[i - 1]) i ++;
            }
            x ++;
        }
        
        while (x <= high) {
            result.push_back(x);
            x ++;
        }
        return result;
    }
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // return approach_1(arr, low, high);
        return approach_2(arr, low, high);
    }
};