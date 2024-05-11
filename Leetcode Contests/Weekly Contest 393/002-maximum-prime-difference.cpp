// https://leetcode.com/problems/maximum-prime-difference/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(sqrt(N))
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    // TC : O(N*sqrt(N))
    int maximumPrimeDifference(vector<int>& nums) {
        int minIndex = -1;
        int maxIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                if (minIndex == -1) minIndex = i;
                maxIndex = i;
            }
        }
        if (minIndex == -1 || maxIndex == -1) return 0;
        return maxIndex - minIndex;
    }
};