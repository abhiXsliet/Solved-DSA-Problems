// https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N)
    // SC : O(N)
    int findLength(vector<int> &color, vector<int> &radius) {
        int n = color.size();
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; i ++) {
            if (!stk.empty() && stk.top().first == color[i] && stk.top().second == radius[i]) {
                stk.pop();
            } else {
                stk.push({color[i], radius[i]});
            }
        }
        return stk.size();
    }
};