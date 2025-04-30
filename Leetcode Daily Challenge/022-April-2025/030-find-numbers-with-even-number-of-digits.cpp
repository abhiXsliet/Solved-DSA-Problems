// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isEvenDigits(int num) {
        int cntDigits = 0;
        while (num) {
            cntDigits += 1;
            num /= 10;
        }
        return cntDigits % 2 == 0;
    }
public:
    // TC : O(Nlog(num))
    // SC : O(1)
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int &num : nums) {
            ans += isEvenDigits(num) ? 1 : 0;
        }
        return ans;
    }
};