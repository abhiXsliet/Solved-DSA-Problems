// https://leetcode.com/problems/tuple-with-same-product/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N^4)
    // SC : O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 3; i ++) {
            for (int j = i + 1; j < n - 2; j ++) {
                for (int k = j + 1; k < n - 1; k ++) {
                    for (int l = k + 1; l < n; l ++) {
                        int a = nums[i], b = nums[j], c = nums[k], d = nums[l];
                        if (a * b == c * d || a * c == b * d || a * d == b * c) {
                            ans += 8;
                        } 
                    }
                }
            }
        }
        return ans;
    }

    // TC : O(N^3)
    // SC : O(N)
    int better(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = n - 1; j > i; j --) {
                unordered_set<int> seen;
                int a = nums[i], b = nums[j];
                int prod = a * b;
                
                for (int k = i + 1; k < j; k ++) {
                    if (!(prod % nums[k]) && seen.count(prod / nums[k])) {
                        ans += 8;
                    }
                    seen.insert(nums[k]);
                }
            }
        }
        return ans;
    }

    // TC : O(N^2)
    // SC : O(N^2)
    int optimal(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;    // {product of pairs, respective product pairs frequency}
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int a = nums[i], b = nums[j];
                mpp[a * b] ++;
            }
        }

        int ans = 0;
        for (auto &it : mpp) {
            int freq = it.second;
            if (freq > 1) {
                ans += (8 * (freq * (freq - 1)) / 2);
            }
        }
        return ans;
    }    

    // TC : O(N^2)
    // SC : O(N^2)
    int optimal_modified(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mpp;    // {product of pairs, respective product pairs frequency}
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int a = nums[i], b = nums[j];
                int prod = a * b;
                ans += (8 * mpp[prod]);
                mpp[prod] ++;
            }
        }
        return ans;
    }    
public:
    int tupleSameProduct(vector<int>& nums) {
        // return brute(nums);      // use 4-loops
        // return better(nums);     // sort & i = 0, j = n - 1 and k = i + 1 to < j (in middle of i, j)
                                    // look for (arr[i]*arr[j])/arr[k] in set in the middle part of (i, j)

        // return optimal(nums);    // find prod. of all pairs with its freq and use 'nCr' : [(n * (n - 1)) / 2] (r == 2)
        return optimal_modified(nums);
    }
};