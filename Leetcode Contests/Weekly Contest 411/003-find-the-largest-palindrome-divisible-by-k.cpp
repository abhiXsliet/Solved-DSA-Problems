// https://leetcode.com/contest/weekly-contest-411/problems/find-the-largest-palindrome-divisible-by-k/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string findOTN(int n) {
        string res = string(n, '9');
        return res;
    }

    string findTwo(int n) {
        if (n == 1) return "8";
        if (n == 2) return "88";
        string res = string(n, '9');
        res[0] = res[n - 1] = '8';
        return res;
    }

    string findFour(int n) {
        if (n == 1) return "8";
        if (n == 2) return "88";
        if (n == 3) return "888";
        if (n == 4) return "8888";
        string res = string(n, '9');
        res[0] = res[1] = res[n - 2] = res[n - 1] = '8';
        return res;
    }

    string findFive(int n) {
        if (n == 1) return "5";
        if (n == 2) return "55";
        string res = string(n, '9');
        res[0] = res[n - 1] = '5';
        return res;
    }

    string findSix(int n) {
        if (n == 1) return "6";
        if (n == 2) return "66";
        string res = string(n, '9');
        res[0] = res[n - 1] = '8';

        int totalSum = 9 * (n - 2) + 8 + 8;

        if (n % 2) {    // odd length
            if (totalSum % 3 == 1) {
                res[n / 2] = '8';
            } else {    // == 2
                res[n / 2] = '7';
            }
        } else {
            int mid1  = n / 2 - 1;
            int mid2  = n / 2;
            if (totalSum % 3 == 1) {
                res[mid1] = res[mid2] = '7';
            } else {    // == 2
                res[mid1] = res[mid2] = '8';
            }
        }

        return res;
    }

    string findSeven(int n) {
        if (n == 1) return "7";
        if (n == 2) return "77";
       
        string res = string(n, '9');
        
        for (int i = 9; i >= 0; i --) {
            
            if (n % 2) {    // odd length : change the middle position only
                res[n / 2] = i + '0';
            } else {
                int mid1 = n / 2 - 1;
                int mid2 = n / 2;
                res[mid1] = res[mid2] = i + '0';
            }

            long rem  = 0;
            for (int j = 0; j < n; j ++) {
                rem =( rem * 10 + (res[j] - '0')) % 7;
            }

            if (rem == 0) // no. is completely divisible by since rem == 0
                return res;
            
        }

        return res;
    }

    string findEight(int n) {
        if (n == 1) return "8";
        if (n == 2) return "88";
        if (n == 3) return "888";
        if (n == 4) return "8888";
        if (n == 5) return "88888";
        if (n == 6) return "888888";

        string res = string(n, '9');
        res[0] = res[n - 1] = res[1] = res[n - 2] = res[2] = res[n - 3] = '8';
        return res;
    }

    string brute(int n, int k) {
        if (k == 1 || k == 3 || k == 9) {
            return findOTN(n);
        } else if (k == 2) {
            return findTwo(n);
        } else if (k == 4) {
            return findFour(n);
        } else if (k == 5) {
            return findFive(n);
        } else if (k == 6) {
            return findSix(n);
        } else if (k == 7) {    // catch
            return findSeven(n);
        } else if (k == 8) {
            return findEight(n);
        } 
        return "No Case Left";
    }
public:
    string largestPalindrome(int n, int k) {
        return brute(n, k);   

        // return optimal(n, k);   // digit DP Pending??
    }
};