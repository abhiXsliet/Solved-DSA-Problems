// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(N) Where N = Nums length
    // SC : O(1)
    ll approach_1(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum          = 0;
        int cntXorTimes = 0;
        int miniLoss    = INT_MAX;

        for (int& num : nums) {
            if ((num^k) > num) {
                sum += (num^k);
                cntXorTimes ++;     // one more time num xored 
            } else {
                sum += num;
            }

            miniLoss = min(miniLoss, abs(num - (num^k)));
        }

        if (cntXorTimes % 2 == 0) {
            return sum;
        } 

        return sum - miniLoss;
    }

    // TC : O(N*log(N))
    // SC : O(N) Where N = Nums length
    ll approach_2(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll originalSum = accumulate(begin(nums), end(nums), 0LL);

        vector<int> profits;
        for (int& num : nums) {
            profits.push_back((num ^ k) - num);
        }

        sort(begin(profits), end(profits), greater<int>());

        for (int i = 0; i < profits.size() - 1; i += 2) {
            ll profit = profits[i] + profits[i + 1];
            if (profit > 0) {
                originalSum += profit;
            }
        }
        return originalSum;
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // return approach_1(nums, k, edges);

        return approach_2(nums, k, edges);
    }
};