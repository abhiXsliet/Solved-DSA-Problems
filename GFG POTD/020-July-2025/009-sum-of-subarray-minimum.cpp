// https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> nextSmallerToLeft(vector<int> &arr, int n) {
        vector<int> nsl(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i ++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) nsl[i] = stk.top();
            stk.push(i);
        }
        return nsl;
    }
    
    vector<int> nextSmallerToRight(vector<int> &arr, int n) {
        vector<int> nsr(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) nsr[i] = stk.top();
            stk.push(i);
        }
        return nsr;
    }
  public:
    // TC : O(N)
    // SC : O(N)
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> nsl = nextSmallerToLeft(arr, n);
        vector<int> nsr = nextSmallerToRight(arr, n);
        
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            int left  = (i - nsl[i]);
            int right = (nsr[i] - i);
            
            ans += (arr[i] * (left * right));
        }
        return ans;
    }
};