// https://leetcode.com/problems/find-lucky-integer-in-an-array/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        int val = -1, cnt = 0, luckyNum = -1;

        for (int i = 0; i < n; i ++) {
            if (arr[i] != val) {
                val = arr[i];
                cnt = 1;
            } else if (arr[i] == val) cnt ++;

            if (val == cnt && ((i == n - 1) || (i + 1 < n && arr[i] != arr[i + 1]))) {
                luckyNum = val;
            }
        }

        return luckyNum;
    }

    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& arr) {
        int n = arr.size();
        int luckyNum = -1;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i ++) {
            mpp[arr[i]] ++;
        }
        for (auto &it : mpp) {
            if (it.first == it.second) {
                luckyNum = max(luckyNum, it.second);
            }
        }
        return luckyNum;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<int>& arr) {
        int n = arr.size();
        
        for (int &num : arr) {
            int val = (num & 65535);
            if (val <= n) {
                arr[val - 1] += (1 << 16);  // pow(2, 16) or 65535
            }
        }

        for (int num = n; num >= 1; num --) {
            int cnt = (arr[num - 1] >> 16);
            if (cnt == num) return num;
        }

        return -1;
    }
public:
    int findLucky(vector<int>& arr) {
        // return approach_1(arr);
        // return approach_2(arr);
        return approach_3(arr);
    }
};