// https://leetcode.com/problems/build-an-array-with-stack-operations/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // TC = O(N)
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;

        int stream = 1;
        int idx    = 0;

        while(idx < target.size() && stream <= n) {
            result.push_back("Push");

            if (target[idx] == stream) {
                idx++;
            }
            else {
                result.push_back("Pop");
            }
            stream++;
        }

        return result;
    }
};