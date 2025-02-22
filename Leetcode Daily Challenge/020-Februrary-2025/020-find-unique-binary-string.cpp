// https://leetcode.com/problems/find-unique-binary-string/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    // TC : O(2^N)
    // SC : O(N) Due to recursive depth
    void solve(unordered_set<string>& st, int n, string bin, string curr, string& result) {
        if (n == 0) {
            if (!st.count(curr)) {
                result = curr;
            }
            return;
        }

        for (int j = 0; j < bin.length(); j ++) {
            if (!result.empty()) return;

            curr.push_back(bin[j]);
            solve(st, n - 1, bin, curr, result);
            curr.pop_back();
        }   
    }

    // TC : O(2^N)
    // SC : O(N) space used by unordered_set
    string approach_1(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(begin(nums), end(nums));
        string result;
        solve(st, n, "01", "", result);
        return result;
    }

    // TC : O(2^N)
    // SC : O(N) space used by unordered_set
    string approach_2(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (string &num : nums) {
            st.insert(stoi(num, 0, 2)); // Here 2 is the base number (meaning string is interpreted as binary no.) by default it is 10
        }

        int power = (pow(2, n) - 1);    // 2^n no.s can be made with a string of len 'n' consists only of '0' or '1'
        
        string result;
        for (int num = 0; num <= power; num ++) {
            if (!st.count(num)) {
                result = bitset<16>(num).to_string();    // creates a 16 bits number and convert it into a string
                return result.substr(16 - n);
            }
        }
        return "";
    }

    // TC : O(N)
    // SC : O(N) space used by unordered_set
    string approach_2_improved(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (string &num : nums) {
            st.insert(stoi(num, 0, 2)); // Here 2 is the base number (meaning string is interpreted as binary no.) by default it is 10
        }
        
        string result;
        for (int num = 0; num <= n; num ++) {
            if (!st.count(num)) {
                result = bitset<16>(num).to_string();    // creates a 16 bits number and convert it into a string
                return result.substr(16 - n);
            }
        }
        return "";
    }


    // TC : O(N)
    // SC : O(1) 
    string approach_3(vector<string>& nums) {
        int n = nums.size();
        string result;
        for (int i = 0; i < n; i ++) {
            result += (nums[i][i] == '0') ? "1" : "0";
        }
        return result;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // return approach_1(nums);     // Backtracking
        // return approach_2(nums);     // Convert the strings into number and store into set. Iterate from 0 to 2^n and check in set
        // return approach_2_improved(nums);    // only checking upto 0 to n can be fine since one of the is absent from 0 to n
        return approach_3(nums);        // Optimal (no space): character toggling for each indices since if at least one index char is different then its a differnt number
    }
};