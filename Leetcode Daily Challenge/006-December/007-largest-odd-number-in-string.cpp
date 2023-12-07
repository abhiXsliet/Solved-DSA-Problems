// https://leetcode.com/problems/largest-odd-number-in-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(1)
    string solve_approach_1(string num) {
        int n = num.length();
        string result;
        int idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            char ch = num[i];
            int number = ch - '0';
            if (number % 2 == 1) {
                idx = i;
                break;
            }
        }

        for (int i = 0; i <= idx; i++) {
            result += num[i];
        }
        return result;
    }

    // TC = O(N)
    // SC = O(1)
    string solve_approach_2(string num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
public:
    string largestOddNumber(string num) {
        // return solve_approach_1(num);

        return solve_approach_2(num);
    }
};