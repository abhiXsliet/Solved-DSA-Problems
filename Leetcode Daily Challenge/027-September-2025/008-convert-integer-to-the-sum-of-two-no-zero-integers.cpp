// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isNoZero(int num) {
        while (num) {
            int rem = num % 10;
            if (!rem) return false;
            num  /= 10;
        }
        return true;
    }

    // TC : O(N * log(N))
    // SC : O(1)
    vector<int> approach_1(int n) {
        for (int i = 1; i < n; i ++) {
            int num1 = i, num2 = n - i;
            if (isNoZero(num1) && isNoZero(num2)) {
                return {num1, num2};
            }
        }
        return {};
    }

    // TC : O(log10(N))
    // SC : O(1)
    vector<int> approach_2(int n) {
        int placeValue = 1, a = n, b = 0;
        while (n > 1) {
            int take = (n % 10 == 1) ? 2 : 1;

            a -= (take * placeValue);
            b += (take * placeValue);

            n = (n - take) / 10;
            placeValue *= 10;
        }
        return {a, b};
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        // return approach_1(n);
        return approach_2(n);
    }
};