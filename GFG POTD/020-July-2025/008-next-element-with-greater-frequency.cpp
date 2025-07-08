// https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> mpp;
        for (int &num : arr) {
            mpp[num] ++;
        }
        
        stack<int> stk; 
        vector<int> result(n, -1);
        
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && mpp[stk.top()] <= mpp[arr[i]]) {
                stk.pop();
            }
            if (!stk.empty()) result[i] = stk.top();
            stk.push(arr[i]);
        }   
        
        return result;
    }
};