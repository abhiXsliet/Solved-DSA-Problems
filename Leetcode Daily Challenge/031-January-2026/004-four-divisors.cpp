// https://leetcode.com/problems/four-divisors/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int divisorSum(int num) {
        int sum = (num + 1);
        int cntDiv = 2;
        for (int i = 2; i * i <= num; i ++) {
            if (num % i == 0) {
                if (i != (num / i)) {
                    sum += (num / i);
                    cntDiv += 1;
                }
                cntDiv += 1;
                sum += i;

                if (cntDiv > 4) return 0;
            }
        }
        return cntDiv == 4 ? sum : 0;
    }

    int approach_1(vector<int> &nums) {
        int n = nums.size();

        int sum = 0;
        for (int &num : nums) {
            sum += divisorSum(num);
        }
        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        return approach_1(nums);
    }
};