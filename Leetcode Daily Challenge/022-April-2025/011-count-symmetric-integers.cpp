// https://leetcode.com/problems/count-symmetric-integers/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:   
    bool isSymmetric(int num) {
        int digits = log10(num) + 1;
        if (digits % 2) return false;
        
        int halfD = digits / 2;
        int k = 0, sum = 0;

        while (k <= digits) {
            if (k <= halfD / 2)
                sum += (num % 10);
            else 
                sum -= (num % 10);
            k ++;
            num /= 10;
        }
        return sum == 0;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_1(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i ++) {
            if (isSymmetric(i)) {
                ans += 1;
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i ++) {
            if (i >= 10 && i <= 99 && i % 11 == 0) {
                ans += 1;
            } else if (i >= 1000 && i <= 9999) {
                int first  = (i / 1000);
                int second = (i / 100) % 10;
                int third  = (i / 10) % 10;
                int fourth = (i % 10);

                if (first + second == third + fourth)
                    ans += 1;
            }
        }
        return ans;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        // return approach_1(low, high);
        return approach_2(low, high);
    }
};