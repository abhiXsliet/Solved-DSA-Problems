// https://leetcode.com/problems/largest-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(N)
    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        vector<string> newNums(n, "");
        for (int i = 0; i < n; i ++) {
            newNums[i] = to_string(nums[i]);
        }

        auto cmp = [&](string& a, string& b) {
            string num_1 = a + b;
            string num_2 = b + a;
            return num_1 < num_2;
        };

        sort(rbegin(newNums), rend(newNums), cmp);

        string result = "";
        for (int i = 0; i < n; i ++) {
            if (result[0] == '0' && newNums[i] == "0")
                continue; 
            result += newNums[i];
        }
        return result;
    }
};