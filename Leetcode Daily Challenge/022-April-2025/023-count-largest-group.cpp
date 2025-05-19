// https://leetcode.com/problems/count-largest-group/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(log(N))
    // SC : O(1)
    int getDigitSum(int digit) {
        int sum = 0;
        while (digit) {
            sum += (digit % 10);
            digit /= 10;
        }
        return sum;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int brute(int n) {
        unordered_map<int, vector<int>> mpp;

        int largestSize = 0;
        for (int i = 1; i <= n; i ++) {
            int sum = getDigitSum(i);
            mpp[sum].push_back(i);
            largestSize = max(largestSize, (int)mpp[sum].size());
        }

        int totalGroups = 0;
        for (auto &it : mpp) {
            if (it.second.size() == largestSize) {
                totalGroups += 1;
            }
        }
        return totalGroups;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    int better(int n) {
        unordered_map<int, int> mpp;

        int largestSize = 0, totalGroups = 0;
        for (int i = 1; i <= n; i ++) {
            int sum = getDigitSum(i);
            mpp[sum] += 1;
            
            if (mpp[sum] > largestSize) {
                largestSize = mpp[sum];
                totalGroups = 1;
            } else if (mpp[sum] == largestSize) {
                totalGroups += 1;
            }
        }
        return totalGroups;
    }
public:
    int countLargestGroup(int n) {
        // return brute(n);
        return better(n);   // One pass
    }
};