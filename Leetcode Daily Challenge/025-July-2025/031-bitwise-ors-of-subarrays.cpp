// https://leetcode.com/problems/bitwise-ors-of-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N)
    // SC : O(N)
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, result;
        for (int &num : arr) {
            unordered_set<int> curr;
            for (auto &val : prev) {
                curr.insert(val | num);
                result.insert(val | num);
            }
            curr.insert(num);
            result.insert(num);
            prev = curr;
        }
        return result.size();
    }
};