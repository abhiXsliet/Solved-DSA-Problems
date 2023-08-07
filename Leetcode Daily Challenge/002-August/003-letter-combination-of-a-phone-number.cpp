// https://leetcode.com/problems/letter-combinations-of-a-phone-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string digits, int index, string mapping[], string output, vector<string>& ans) {
        //base case
        if(index >= digits.length()) {
            ans.push_back(output);
            return ;
        }

        int number = digits[index] - '0';
        string val = mapping[number];
        
        for(int i = 0; i < val.size(); i++) {
            output.push_back(val[i]);
            solve(digits, index+1, mapping, output, ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() == 0)
            return ans;

        string output = "";
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, index, mapping, output, ans);

        return ans;
    }
};