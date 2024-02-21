// https://leetcode.com/problems/bitwise-and-of-numbers-range/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(N)) where n is the maximum number of bits needed to represent the given input integers left and right
    int solve_approach_1(int left, int right) {
        int shiftCnt = 0;
        while (left != right) {
            left  >>= 1;
            right >>= 1;
            shiftCnt ++;
        }
        return (left << shiftCnt);
    }
    
    // TC : O(log(N)) where n is the maximum number of bits needed to represent the given input integers left and right
    int solve_approach_2(int left, int right) {
        while (right > left) {
            right = right & (right - 1);
        }
        return right;
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        // return solve_approach_1(left, right);

        return solve_approach_2(left, right);
    }
};