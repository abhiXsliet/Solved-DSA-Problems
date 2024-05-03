// https://leetcode.com/problems/find-the-integer-added-to-array-ii/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^2 * M) ~= O(N^3)
    // SC : O(N)
    int solve_brute(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n   = nums1.size();
        int m   = nums2.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                
                vector<int> temp = nums1;
                // Erasae both element : nums1[i], nums1[j]
                temp.erase(temp.begin() + i);
                temp.erase(temp.begin() + j - 1);
                
                int diff = nums2[0] - temp[0];

                for(int k = 0; k < m; k ++){   
                    temp[k] += diff;
                }

                if(temp == nums2){  // catch
                    ans = min(ans, diff);
                }
            }
        }
        return ans;
    }

    // TC : O(N)
    // SC : O(1)
    bool isPossible(vector<int>& nums1, vector<int>& nums2, int diff, int n, int m) {
        int i = 0, j = 0, notPossible = 0;
        while (i < n && j < m) {
            if (nums1[i] + diff == nums2[j]) {
                i ++;
                j ++;
            }
            else { // not possilbe so try for next element of nums1
                notPossible ++;
                i ++;
            }
        }
        return notPossible > 2 ? false : true;
    }

    // TC : O(N^2)
    // SC : O(1)
    int solve_better(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n   = nums1.size();
        int m   = nums2.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int diff = nums2[0] - nums1[i];
            // check with diff is it possible to convert nums1 == nums2
            if (isPossible(nums1, nums2, diff, n, m)) {
                ans = min(ans, diff);
            }
        }
        return ans;
    }

    // TC : O(N*log(N))
    // SC : O(1)
    int solve_optimal(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n   = nums1.size();
        int m   = nums2.size();
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++) {
            int diff = nums2[0] - nums1[i];
            // check with diff is it possible to convert nums1 == nums2
            if (isPossible(nums1, nums2, diff, n, m)) {
                ans = min(ans, diff);
            }
        }
        return ans;
    }
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        // return solve_brute(nums1, nums2);    // Try & Remove each 2-elements

        // return solve_better(nums1, nums2);   // check for all diffrences (nums2[0] - nums1[i])
        
        return solve_optimal(nums1, nums2);   // small change in loop
    }
};
