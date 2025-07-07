// https://www.geeksforgeeks.org/problems/next-greater-element/1




#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_1(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            arr.push_back(arr[i]);
        }

        stack<int> stk;
        vector<int> result(n, -1);
        int len = arr.size(); 
        
        for (int i = len - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) result[i % n] = arr[stk.top()];
            stk.push(i); 
        }
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<int> approach_2(vector<int> &arr) {
        int n = arr.size();
        
        stack<int> stk;
        vector<int> result(n, -1);
        int len = 2 * arr.size(); 
        
        for (int i = len - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top() % n] <= arr[i % n]) {
                stk.pop();
            }
            if (!stk.empty()) result[i % n] = arr[stk.top() % n];
            stk.push(i); 
        }
        return result;
    }
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // return approach_1(arr);
        return approach_2(arr);  // No input modify
    }
};