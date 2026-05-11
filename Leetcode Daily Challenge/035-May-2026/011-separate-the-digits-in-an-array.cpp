// https://leetcode.com/problems/separate-the-digits-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> getDigits(int val) {
        vector<int> digits;
        while (val > 0) {
            digits.push_back(val % 10);
            val /= 10;
        }
        reverse(begin(digits), end(digits));
        return digits;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int &num : nums) {
            vector<int> digits = getDigits(num);
            for (int &d : digits) result.push_back(d);
        }
        return result;
    }
};