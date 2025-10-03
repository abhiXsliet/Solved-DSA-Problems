// https://www.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void solve(vector<int> &arr, int idx, string temp, vector<string> &result, unordered_map<int, string> &mpp) {
        if (idx >= arr.size()) {
            result.push_back(temp);
            return;
        }
        
        string str = mpp[arr[idx]];
        if (str.empty()) {
            solve(arr, idx + 1, temp, result, mpp);
        } else {
            for (char &ch : str) {
                temp.push_back(ch);
                solve(arr, idx + 1, temp, result, mpp);
                temp.pop_back();
            }
        }
    }
  public:
    /*
        Time Complexity       : O(n * 4^n)
        Auxiliary Space       : O(n)
        Recursive Stack Space : O(n)
    */
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> result;
        unordered_map<int, string> mpp {
            {0, ""},
            {1, ""}, 
            {2, "abc"}, 
            {3, "def"},
            {4, "ghi"}, 
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        string temp;
        solve(arr, 0, temp, result, mpp);
        return result;
    }
};