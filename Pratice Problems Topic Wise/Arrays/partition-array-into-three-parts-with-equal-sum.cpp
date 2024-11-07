// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int total = accumulate(begin(arr), end(arr), 0);
        if (total % 3 != 0) return false;

        int eachPart = total / 3;
        int sum = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == eachPart) {
                cnt++;
                sum = 0;
            }
            if (cnt == 2 && i < n - 1) return true;  // Ensure there's enough left for the third part
        }
        
        return false;
    }
};