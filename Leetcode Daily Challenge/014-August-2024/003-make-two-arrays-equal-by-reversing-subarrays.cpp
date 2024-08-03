// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool approach_1(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (int& t : target) {
            mpp[t] ++;
        }

        for (int& num : arr) {
            if (!mpp.count(num)) {
                return 0;
            } else {
                mpp[num] --;
                if (mpp[num] == 0) {
                    mpp.erase(num);
                }
            }
        }
        return 1;
    }

    // TC : O(N*log(N))
    // SC : O(N*log(N))
    bool approach_2(vector<int>& target, vector<int>& arr) {
        sort(begin(target), end(target));
        sort(begin(arr), end(arr));
        return target == arr;
    }
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // return approach_1(target, arr);

        return approach_2(target, arr);
    }
};