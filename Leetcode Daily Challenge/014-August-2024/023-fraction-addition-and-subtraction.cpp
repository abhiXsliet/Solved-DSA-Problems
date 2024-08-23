// https://leetcode.com/problems/fraction-addition-and-subtraction/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    string brute(string expression) {
        int n = expression.size();
        
        vector<int> storeDeno;  // store denominator, digit after '/'
        for (int i = 0; i < n; i ++) {
            if (expression[i] == '/') {
                int d = 0;
                if (i + 2 < n && isdigit(expression[i + 1]) && isdigit(expression[i + 2])) {
                    string str;
                    str += expression[i + 1];
                    str += expression[i + 2];
                    d = stoi(str);
                } else {
                    d = expression[i + 1]  - '0';
                }
                storeDeno.push_back(d);
            }
        }
        
        int calcLCM = 1;
        for (int i = 0; i < storeDeno.size(); i ++) {
            calcLCM = lcm(calcLCM, storeDeno[i]);
        }

        vector<int> storeNumr;  // store numerator, digit before '/' 
        for (int i = 1; i < n; i ++) {
            
            int s = 1;
            if (i >= 2 && expression[i - 2] == '-') s *= -1;    // check for sign
            if (i >= 3 && expression[i - 3] == '-') s *= -1;    // check for sign

            if (expression[i] == '/') { 
                int d = 0;
                if (i - 2 >= 0 && isdigit(expression[i - 1]) && isdigit(expression[i - 2])) {
                    string str;
                    str += expression[i - 2];
                    str += expression[i - 1];
                    d = s * stoi(str);
                } else {
                   d = s * (expression[i - 1] - '0');
                }
                storeNumr.push_back(d);
            } 
        }

        int numerator = 0, denominator = calcLCM;
        for (int i = 0; i < storeNumr.size(); i ++) {
            int mul       = (calcLCM / storeDeno[i]);
            storeNumr[i] *= mul;
            numerator    += storeNumr[i];
        }

        int getGCD = gcd(numerator, denominator);
        numerator   /= getGCD;
        denominator /= getGCD;

        return to_string(numerator) + "/" + to_string(denominator);
    }

    // TC : O(N)
    // SC : O(1)
    string optimal(string expression) {
        int n = expression.size();

        int initialNumr = 0;
        int initialDeno = 1;
        int i = 0;

        while (i < n) {
            int currNumr = 0;
            int currDeno = 0;
            bool isNegative = 0;

            isNegative = (expression[i] == '-');
            
            if (expression[i] == '-' || expression[i] == '+') {
                i ++;
            }

            // build curr numerator
            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNumr = (currNumr * 10) + val;
                i ++;
            }

            if (isNegative) currNumr = -currNumr;

            // skip the '/' sign
            i ++;

            // build the denominator
            while(i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDeno = (currDeno * 10) + val;
                i ++;
            }

            initialNumr = initialNumr * currDeno + initialDeno * currNumr;
            initialDeno = initialDeno * currDeno;
        }

        int gcdVal = abs(__gcd(initialNumr, initialDeno));

        initialNumr /= gcdVal;
        initialDeno /= gcdVal;

        return to_string(initialNumr) + "/" + to_string(initialDeno);
    }
public:
    string fractionAddition(string expression) {
        // return brute(expression);    // Simulation like how we solve fraction in general

        return optimal(expression);
    }
};