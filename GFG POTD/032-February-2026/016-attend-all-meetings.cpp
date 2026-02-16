// https://www.geeksforgeeks.org/problems/attend-all-meetings/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(begin(arr), end(arr));
        int prev = arr[0][1];
        for (int i = 1; i < arr.size(); i ++) {
            if (arr[i][0] < prev) {
                return false;
            } 
            prev = arr[i][1];
        }
        return true;
    }
};