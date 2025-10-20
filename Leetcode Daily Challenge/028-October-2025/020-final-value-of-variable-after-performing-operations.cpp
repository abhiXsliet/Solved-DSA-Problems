// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (string &str : operations) {
            if (str[1] == '-') {
                result -= 1;
            } else {
                result += 1;
            } 
        }
        return result;
    }
};