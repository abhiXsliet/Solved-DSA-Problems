// https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> getNextSmaller(vector<int> &arr, int n) {
        vector<int> nse(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {  // non-strict
                stk.pop();
            }
            if (!stk.empty()) nse[i] = stk.top();
            stk.push(i);
        }
        return nse;
    }

    vector<int> getPrevSmaller(vector<int> &arr, int n) {
        vector<int> pse(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {   // strict
                stk.pop();
            }
            if (!stk.empty()) pse[i] = stk.top();
            stk.push(i);
        }
        return pse;
    }
    
    vector<int> getNextGreater(vector<int> &arr, int n) {
        vector<int> result(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {  // non-strict
                stk.pop();
            }
            if (!stk.empty()) result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
    vector<int> getPrevGreater(vector<int> &arr, int n) {
        vector<int> pge(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[stk.top()] < arr[i]) {   // strict
                stk.pop();
            }
            if (!stk.empty()) pge[i] = stk.top();
            stk.push(i);
        }
        return pge;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> nse = getNextSmaller(arr, n);
        vector<int> pse = getPrevSmaller(arr, n);
        vector<int> nge = getNextGreater(arr, n);
        vector<int> pge = getPrevGreater(arr, n);
        
        long long minSubArrSum = 0, maxSubArrSum = 0;
        for (int i = 0; i < n; i ++) {
            long long c1 = (long long)(i - pse[i]) * (nse[i] - i);
            long long c2 = (long long)(i - pge[i]) * (nge[i] - i);
            
            minSubArrSum += (c1 * arr[i]);
            maxSubArrSum += (c2 * arr[i]);
        }
        return (int)(maxSubArrSum - minSubArrSum);
    }
};