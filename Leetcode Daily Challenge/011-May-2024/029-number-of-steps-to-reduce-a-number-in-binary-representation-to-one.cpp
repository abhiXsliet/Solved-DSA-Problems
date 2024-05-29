// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void addOne(string& s) {
        int n = s.length();
        int i = n - 1;
        while (i >= 0 && s[i] != '0') {
            s[i] = '0';
            i --;
        }
        if (i < 0) {
            s = '1' + s;
        } else {
            s[i] = '1';
        }
    }

    // TC : O(N*N) Where N = s.length()
    // SC : O(1)
    int approach_1(string& s) {
        int operation = 0;
        while (s.length() > 1) {
            if (s[s.length() - 1] == '1') {
                addOne(s);
            } else {
                s.pop_back();
            }
            operation += 1;
        }
        return operation;
    }

    // TC : O(N) Where N = s.length()
    // SC : O(1)
    int approach_2(string& s) {
        int n = s.length();
        int carry     = 0;
        int operation = 0;
        for (int i = n - 1; i > 0; i --) {
            if (((s[i] - '0') + carry % 2) == 1) {    // odd
                operation += 2;
                carry = 1;
            } else {
                operation += 1;
            }
        }
        return operation + carry;
    }
public:
    int numSteps(string s) {
        // return approach_1(s);

        return approach_2(s);
    }
};