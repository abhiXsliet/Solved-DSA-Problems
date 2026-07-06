// https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1/




#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    int maxPathSum(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        long long sumA = 0, sumB = 0;
        long long ans = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                sumA += a[i++];
            }
            else if (a[i] > b[j]) {
                sumB += b[j++];
            }
            else {
                ans += max(sumA, sumB) + a[i];
                sumA = 0;
                sumB = 0;
                i++;
                j++;
            }
        }

        while (i < a.size()) sumA += a[i++];
        while (j < b.size()) sumB += b[j++];

        ans += max(sumA, sumB);

        return ans;
    }
};