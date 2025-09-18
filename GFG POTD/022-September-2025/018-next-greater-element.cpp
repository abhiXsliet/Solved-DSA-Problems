// https://www.geeksforgeeks.org/problems/next-greater-element/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> stk;
        for (int i = 2*n - 1; i >= 0; i --) {
            while (!stk.empty() && stk.top() <= arr[i % n]) {
                stk.pop();
            }
            result[i % n] = stk.empty() ? -1 : stk.top();
            stk.push(arr[i % n]);
        }
        return result;
    }
};