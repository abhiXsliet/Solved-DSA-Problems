// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int M = 1e9 + 7;
    int power(int a, int b ) {
        int res = 1;
        while(b > 0) {
            if(b&1) {//odd
                res = (1LL * res * (a) %M) % M;
            }
            b = b >> 1;
            a = (1LL * (a) % M * (a) % M) % M; 
        }
        return res;
    }
public:
    // TC : O(N*log(N))
    // SC : O(1)
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int i = 0, j = n - 1;
        int result = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                int diff   = j - i;
                int subSeq = power(2, diff);

                result    = (result + subSeq) % M;
                i++;
            }
            else j --;
        }
        return result;
    }
};