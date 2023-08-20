// https://leetcode.com/contest/weekly-contest-358/problems/max-pair-sum-in-an-array/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int>freq(10, 0);
        vector<vector<int>> store(10);
        for(auto& num: nums) {
            int maxDigit = 0;
            int n = num;
            while (n > 0) {
                maxDigit = max(maxDigit, n % 10);
                n /= 10;
            }
            freq[maxDigit]++;
            store[maxDigit].push_back(num);
        }
        
        int maxSum = -1;
        for(int i = 9; i >= 1; i--) {
            if(freq[i] >= 2) {
                sort(store[i].rbegin(), store[i].rend());
                maxSum = max(maxSum, store[i][0] + store[i][1]);
            }
        }
        return maxSum ;
    }
}; 