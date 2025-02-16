// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int checkPunish(int squareNo, int num, int sum) {
        if (squareNo == 0) {
            return sum == num;
        }

        if (sum > num)
            return false;

        for (int i = 10; i <= 10000; i *= 10) {
            if (checkPunish(squareNo/i, num, sum + squareNo % i)) 
                return true;
        }

        return false;
    }

    // TC : O(2^log10(n^2)) where n = s.length()
    // SC : O(log10(n^2)) Recursive call stack space
    bool checkPunishment(string s, int num, int idx, int sum, vector<vector<int>>& dp) {
        if (idx >= s.length()) {
            return sum == num;
        }
        if (sum > num) {
            return false;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        int possible = 0;
        for (int i = idx; i < s.length(); i ++) {
            // Extract the substring from index to i
            int substrVal = stoi(s.substr(idx, i - idx + 1));
            possible |= checkPunishment(s, num, i + 1, sum + substrVal, dp);
            if(possible) return true;
        }
        return dp[idx][sum] = possible;
    }

    // TC : O(n * 2^log10(n^2))
    // SC : O(log10(n^2)) space used by recursive call stack without memoization
    // SC : O(log(n^2) * n) + log10(n^2) space used by dp array + recursive call stack
    int approach_1(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            int val = i * i;
            string square = to_string(val);
            vector<vector<int>> dp(square.length(), vector<int>(i + 1, -1));
            if (checkPunishment(square, i, 0, 0, dp)) {
                sum += (val);
            }
        }
        return sum;
    }

    // TC : O(n * 2^log10(n^2))
    // SC : O(log10(n^2)) recursive call stack space
    int approach_2(int n) {
        int sum = 0;
        for (int num = 1; num <= n; num ++) {
            if (checkPunish(num*num, num, 0)) {
                sum += (num * num);
            }
        }
        return sum;
    }
public:
    int punishmentNumber(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};