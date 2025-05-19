// https://leetcode.com/problems/count-good-triplets-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N^3)
    // SC : O(1)
    int approach_1(vector<int> &arr, int a, int b, int c) {
        int n = arr.size();
        int counts = 0;
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k < n; k ++) {
                        if (abs(arr[k] - arr[j]) <= b && abs(arr[k] - arr[i]) <= c) {
                            counts += 1;
                        }
                    }
                }
            }
        }
        return counts;
    }
    
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        return approach_1(arr, a, b, c);
    }
};