// https://leetcode.com/problems/reordered-power-of-2/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(no. of digits of n)
    // SC : O(1)
    int getEquivalent(int n) {
        long result = 0;
        while (n) {
            int remain = (n % 10);
            long power = pow(10, remain);
            result += power;
            n      /= 10;
        }
        return result;
    }

    vector<int> storeDigits(int n) {
        vector<int> result(10, 0);
        while (n) {
            result[n % 10] += 1;
            n /= 10;
        }
        return result;
    }

    bool isPowerOf2(int n) {
        return ( (n > 0) && ((n & (n - 1)) == 0) );
    }
    
    bool solve(int idx, string &s, int len) {
        if (idx == len) {
            int val = stoi(s);
            return isPowerOf2(val);
        }

        for (int i = idx; i < len; i ++) {
            swap(s[i], s[idx]);

            if (s[0] != '0' && solve(idx + 1, s, len)) return true;

            swap(s[i], s[idx]);
        }

        return false;
    }

    // TC : O(len!)
    // SC : O(len)
    bool approach_1(int n) {
        string s = to_string(n);
        int len = s.length();
        return solve(0, s, len);
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_2(int n) {
        static unordered_set<string> st;

        // only build once
        if (st.empty()) {
            for (int i = 0; i <= 29; i ++) {
                int power = (1 << i);
                string str = to_string(power);
                sort(begin(str), end(str));
                st.insert(str);
            }
        }

        string num = to_string(n);
        sort(begin(num), end(num));

        return st.count(num);
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_3(int n) {
        // stores the digits of n into a vector and compare with pow(2, i)
        vector<int> input = storeDigits(n);

        for (int i = 0; i <= 29; i ++) {
            int power = (1 << i);
            if (input == storeDigits(power)) {
                return true;
            }
        }

        return false;
    }

    // TC : O(1)
    // SC : O(1)
    bool approach_4(int n) {
        // use len of 10-bits as vector to store digits frequency
        int input = getEquivalent(n);

        for (int i = 0; i <= 29; i ++) {
            int power = (1 << i);
            if (input == getEquivalent(power)) {
                return true;
            }
        }

        return false;
    }
public:
    bool reorderedPowerOf2(int n) {
        // return approach_1(n);    // Brute
        // return approach_2(n);
        // return approach_3(n);
        return approach_4(n);
    }
};