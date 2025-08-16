// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N * log(N))
    // SC : O(N)
    string findLargest(vector<int> &arr) {
        vector<string> nums;
        for (int &val : arr) {
            nums.push_back(to_string(val));
        }
        
        auto cmp = [&](string a, string b) {
            string num1 = a + b;
            string num2 = b + a;
            return num1 > num2;
        };
        
        sort(begin(nums), end(nums), cmp);
        
        string largestNum;
        for (string &num : nums) {
            largestNum += num;
        }
        return largestNum[0] == '0' ? "0" : largestNum;
    }
};