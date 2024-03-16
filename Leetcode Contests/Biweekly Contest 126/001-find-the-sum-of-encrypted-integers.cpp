// https://leetcode.com/contest/biweekly-contest-126/problems/find-the-sum-of-encrypted-integers/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*M)  Where N = length of the array nums
    // SC : O(M)    Where M = length of max_number
    int solve_1(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) {
            string s = to_string(num);
            int len  = s.length();
            if (len > 1) {
                char maxEle = '0';
                for (int i = 0; i < len; i++) {
                    if (s[i] > maxEle) {
                        maxEle = s[i];
                    }
                    if (maxEle == '9') break;
                }
                
                string x = string(len, maxEle);
                ans += stoi(x);
            }
            else {
                ans += num;
            }
        }
        return ans;
    }
    
    // TC : O(n * log10(max_num))
    // SC : O(1)
    int solve_2(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) {
            int temp = num;
            int maxi = 0;
            while(temp > 0) {
                maxi = max(maxi, temp % 10);
                temp /= 10;
            }
            int encryptedNum = 0;
            temp = num;
            while(temp > 0) {
                encryptedNum = encryptedNum * 10 + maxi;
                temp /= 10;
            }
            ans += encryptedNum;
        }
        return ans;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        // return solve_1(nums);
        
        return solve_2(nums);
    }
};