// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int opr = 0;
        for (int &num : nums) {
            int val = num % 3;
            opr += min(val, 3 - val);
        }
        return opr;
    }
};