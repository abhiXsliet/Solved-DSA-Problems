// https://leetcode.com/problems/maximal-rectangle/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    using ll = long long;

    vector<int> getNextSmaller(vector<int> &arr, int n) {
        vector<int> nse(n, n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i --) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
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
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) pse[i] = stk.top();
            stk.push(i);
        }
        return pse;
    }

    ll getMaximumRowArea(vector<int> &arr, int n) {
        vector<int> nse = getNextSmaller(arr, n);
        vector<int> pse = getPrevSmaller(arr, n);

        ll maxArea = 0;
        for (int i = 0; i < n; i ++) {
            ll width  = (nse[i] - pse[i] - 1);
            ll height = (arr[i]);
            maxArea   = max(maxArea, width*height);
        }
        return maxArea;
    }

    ll getMaxRectangleArea(vector<vector<char>> &vec) {
        int m = vec.size(), n = vec[0].size();
        vector<int> height(n, 0);
        ll maxRectangleArea = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (vec[i][j] == '1') {
                    height[j] ++;
                } else {
                    height[j] = 0;
                }
            }
            maxRectangleArea = max(maxRectangleArea, getMaximumRowArea(height, n));
        }
        return maxRectangleArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        return getMaxRectangleArea(matrix);
    }
};