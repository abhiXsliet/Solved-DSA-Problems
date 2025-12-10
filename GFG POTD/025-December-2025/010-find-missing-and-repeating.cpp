// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            // Swap elements till it not reached to its correct indexes
            if (arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
                i--;
            }
        }
        
        // find the duplicate and missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                result.push_back(arr[i]);   // duplicate number
                result.push_back(i + 1);    // missing number
                break;
            }
        }
        
        return result;
    }
};