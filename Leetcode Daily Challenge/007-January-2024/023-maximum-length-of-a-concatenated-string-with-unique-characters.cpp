// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(26) ~= O(1)
    // SC : O(26) ~= O(1)
    bool hasDuplicate(string& s1, string& s2) {
        int arr[26] = {0};

        for (char& ch : s1) {
            if (arr[ch - 'a'] > 0)  // {"aa", "bb"}
                return true;
            arr[ch - 'a'] ++;
        }

        for (char& ch : s2) {
            if (arr[ch - 'a'] > 0) 
                return true;
        }
        return false;
    }

    // TC : O(2^N) Where N = arr.size();
    // SC : O(N) -> Recursive Stack
    int solve_1(vector<string>& arr, int n, int idx, string temp) {
        if (idx >= n) return temp.length();

        int include = 0, exclude = 0;

        if (hasDuplicate(arr[idx], temp)) {
            exclude = solve_1(arr, n, idx + 1, temp);
        }
        else {
            exclude = solve_1(arr, n, idx + 1, temp);
            include = solve_1(arr, n, idx + 1, temp + arr[idx]);
        }

        return max(include, exclude);
    }

    // TC : O(2^N) Where N = arr.size();
    // SC : O(N) -> Recursive Stack
    void solve_2(vector<int>& uniqueString, int& result, int temp, int idx) {
        result = max(result, __builtin_popcount(temp)); // temp holds the concatenated string in interger form

        for (int i = idx; i < uniqueString.size(); i++) {

            if ((uniqueString[i] & temp) == 0) // means have only unique chars
                solve_2(uniqueString, result, (temp | uniqueString[i]), i + 1);
        }
    }

    // TC : O(N * M + 2^N), where 'N' is the size of array & 'M' is the average length of the strings in the array
    // SC : O(N)
    int solve_approach_2(vector<string>& arr, int n) {
        vector<int> uniqueString;

        // remove string which has duplicate chars {"aa", "bb", "ae"}
        for (string& s : arr) {
            unordered_set<char> st(begin(s), end(s));
            
            if (st.size() != s.length()) { // s has duplicate chars
                continue;
            }
            
            int val = 0;
            for (char& ch : s) {
                val = (val | (1 << (ch - 'a')));
            }

            uniqueString.push_back(val);
        }

        int result = 0;
        int temp   = 0;
        solve_2(uniqueString, result, temp, 0); //  idx, temp(converted the string into integer)
        return result;
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();

        // return solve_1(arr, n, 0, "");

        return solve_approach_2(arr, n);
    }
};