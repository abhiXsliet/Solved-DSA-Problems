// https://www.geeksforgeeks.org/problems/longest-subarray-length--202010/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    vector<int> getNge(vector<int> &arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> result(n, n);
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> getPge(vector<int> &arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> result(n, -1);
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) result[i] = stk.top();
            stk.push(i);
        }
        return result;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> nge = getNge(arr);
        vector<int> pge = getPge(arr);
        
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            int len = (nge[i] - pge[i] - 1);
            if (arr[i] <= len) {
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};