// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log3(15)) 
    // SC : O(1)
    bool brute_1(int n) {
        vector <int> powerOf3;
        for (int i = 0; i <= 14; i ++) {
            powerOf3.push_back(pow(3, i));
        }

        for (int i = powerOf3.size() - 1; i >= 0; i --) {
            if (n >= powerOf3[i]) {
                n -= powerOf3[i];
            }
            if (n == 0) return true;
        }
        return false;
    }

    // TC : O(log3(15)) 
    // SC : O(1)
    bool brute_2(int n) {
        for (int i = 14; i >= 0; i --) {
            int powerOf3 = pow(3, i);
            if (n >= powerOf3) {
                n -= powerOf3;
            }
            if (n == 0) return true;
        }
        return false;
    }

    // TC : O(log3(n))
    // SC : O(1)
    bool better(int n) {
        int power = 0;
        while (pow(3, power) <= n) power ++;

        while (n > 0) {
            int powerOf3 = pow(3, power);
            
            if (n >= powerOf3) {
                n -= powerOf3;
            } 

            if (n >= powerOf3) // still 'n' is greater than powerOf3 meaning : it violates the condn of distinct powers
                return false;

            power --;
        }
        return true;
    }

    // TC : O(log3(n))
    // SC : O(1)
    bool optimal(int n) {
        while (n) {
            if (n % 3 == 2)         // 15 : 120 (Ternary Representation), here 2 depicts 2*3^1 (power is not distinct)
                return false;
            n /= 3; 
        }
        return true;
    }
public:
    bool checkPowersOfThree(int n) {
        // return brute_1(n);
        // return brute_2(n);
        // return better(n);
        return optimal(n);      // Convert to ternary representation (TR), and if any digit is 2, 
                                // it indicates to use the same power twice, violating condition of distinct powers

    }
};