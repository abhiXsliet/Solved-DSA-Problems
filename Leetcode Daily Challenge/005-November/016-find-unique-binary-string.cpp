// https://leetcode.com/problems/find-unique-binary-string/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N)
    // SC = O(N)
    string solve_approach_1(vector<string>& nums, int n) {
        unordered_set<int> st;

        for (string &s : nums) {
            int num = stoi(s, 0, 2);
            st.insert(num);
        }

        string result = "";

        for (int number = 0; number <= n; number++) {
            if (st.find(number) == st.end()) {
                
                result = bitset<16>(number).to_string();

                return result.substr(16-n, n);
            }
        }

        return "";
    }

    // TC = O(N)
    // SC = O(1)
    string solve_approach_2(vector<string>& nums, int n) {
        string result = "";

        for (int i = 0; i < n; i++) {
            int num = nums[i][i];

            if (num == '0') {
                result += '1';
            }
            else {
                result += '0';
            }
        }

        return result;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // return solve_approach_1(nums, nums.size());

        return solve_approach_2(nums, nums.size());
    }
};