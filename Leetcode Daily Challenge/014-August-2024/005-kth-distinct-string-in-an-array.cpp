// https://leetcode.com/problems/kth-distinct-string-in-an-array/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    string approach_1(vector<string>& arr, int k) {
        string res;
        unordered_map<string, int> mpp;
        for (string& s : arr) 
            mpp[s] ++;
            
        for (auto& str : arr) {
            if (mpp[str] == 1) k --;
            if (k == 0) {
                res = str;
                break;
            }
        }
        return res;
    }
public:
    string kthDistinct(vector<string>& arr, int k) {
        return approach_1(arr, k);   // HASHMAP
    }
};