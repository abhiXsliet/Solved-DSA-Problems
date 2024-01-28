// https://leetcode.com/contest/weekly-contest-382/problems/find-the-maximum-number-of-elements-in-subset/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    // TC : O(N * log(N)) 
    // SC : O(N)
    int solve_brute(vector<int>& nums) {
        unordered_map<ll, ll> mpp;
        
        for (int num : nums) mpp[num] ++;

        int maxCnt = 0;

        for (int num : nums) {
            
            ll val = num;
            int cnt = 0;
            
            while (mpp[val] > 1) {
                if (val == 1) {
                    if (mpp[val] % 2) cnt = mpp[val];
                    else cnt = mpp[val] - 1;

                    maxCnt = max(maxCnt, cnt);
                    break;
                }

                cnt  += 2;    // subset of 2-elements
                if (val > 1e5) break;
                val *= val;   // lookup for the next element
            }
            if (mpp[val] == 0) cnt--;
            
            if (mpp[val] >= 1) {
                if (mpp[val] == 1) cnt ++;
                else cnt --;
            }
            
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
public:
    int maximumLength(vector<int>& nums) {
        return solve_brute(nums);
    }
};