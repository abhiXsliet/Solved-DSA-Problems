// https://leetcode.com/problems/container-with-most-water/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        
        int maxArea = INT_MIN;
        
        int j = n - 1;
        int i = 0;
        
        while (i < j) {
            if (arr[i] > arr[j]) {
                maxArea = max(maxArea, arr[j]*(j - i));
                j--;
            } else {
                maxArea = max(maxArea, arr[i] * (j - i));
                i++;
            }
        }
        return maxArea;
    }
};