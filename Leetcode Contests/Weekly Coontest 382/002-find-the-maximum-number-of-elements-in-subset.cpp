// https://leetcode.com/contest/weekly-contest-382/problems/find-the-maximum-number-of-elements-in-subset/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;
    
    // TC : O(N)
    // SC : O(N)
    int solve_brute(vector<int>& nums, int n) {
        unordered_map<ll, int> mpp;
        
        for (int num : nums) mpp[num] ++;

        // calculate for ones
        int maxCnt = mpp.count(1) ? (mpp[1] % 2 == 0 ? mpp[1] - 1 : mpp[1]) : 0;

        for (int num : nums) {
            int cnt = 0;
            ll val  = num;
            while (mpp.count(val) && mpp[val] >= 2 && val != 1 && val <= 1e9) {
                cnt += 2;
                val *= val;
            } 
            
            if (mpp.count(val)) cnt++;
            else cnt --;

            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
    
    // TC : O(N) but at worst O(N*log(N)) since map is implemented using balanced bst (red-black tree) which takes log(N) for insertion, deletion, searching operations
    // SC : O(N)
    int solve_better(vector<int>& nums, int n) {
        map<ll, int> mpp;
        
        for (int& num : nums) {
            mpp[num] ++;
        }
        
        int ans = 0;
        for (auto& [ele, freq] : mpp) {
            int maxEle = 0;
            ll prevEle = ele;
            
            while(mpp.count(prevEle) && mpp[prevEle]) {
                if (prevEle == 1) 
                    maxEle += mpp[prevEle];
                else if (mpp[prevEle] >= 2)
                    maxEle += 2;
                else if (mpp[prevEle] == 1) {
                    maxEle += 1;
                    break;
                }
                
                mpp[prevEle] = 0;
                
                if (prevEle > 1e5) break;
                prevEle *= prevEle;
            }
            
            ans = max(ans, maxEle - (maxEle%2 == 0));
        }
        return ans;
    }
public:
    int maximumLength(vector<int>& nums) {
        // return solve_brute(nums, nums.size());

        return solve_better(nums, nums.size());
    }
};