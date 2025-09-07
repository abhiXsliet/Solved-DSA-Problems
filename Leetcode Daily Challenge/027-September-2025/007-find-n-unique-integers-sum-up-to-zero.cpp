// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 1; i <= n/2; i ++) {
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2) result.push_back(0);
        return result;
    }
};