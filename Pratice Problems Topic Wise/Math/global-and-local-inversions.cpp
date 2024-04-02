// https://leetcode.com/problems/global-and-local-inversions/description/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long ll;

    // TC : O(log(N))
    // SC : O(N)
    int merge(vector<int>& nums, int start, int mid, int end) {
        int cnt = 0;
        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<int> left(n1);
        vector<int> right(n2);

        int i = 0, j = 0, k = start;
        while(i < n1) {
            left[i] = nums[k];
            i ++, k ++;
        }
        k = mid + 1;
        while(j < n2) {
            right[j] = nums[k];
            j ++, k ++;
        }

        i = 0, j = 0, k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                k ++, i ++;
            }
            else {
                cnt += (n1 - i);
                nums[k] = right[j];
                k ++, j ++;
            }
        }
        while(i < n1) {
            nums[k] = left[i];
            k ++, i ++;
        }
        while (j < n2) {
            nums[k] = right[j];
            k ++, j ++;
        }
        return cnt;
    }

    int getLocalInv(vector<int>& nums, int n) {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                cnt ++;
            }
        }
        return cnt;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    ll getGlobalInv(vector<int>& nums, int start, int end) {
        ll cnt = 0;
        if (start >= end) return 0;
        int mid = start + (end - start) / 2;
        cnt += getGlobalInv(nums, start, mid);
        cnt += getGlobalInv(nums, mid + 1, end);
        cnt += merge(nums, start, mid, end);
        return cnt;
    }

    // TC : O(N)
    // SC : O(1)
    bool solve_optimal(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            if (abs(nums[i] - i) > 1)
                return false;
        }
        return true;
    }
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();

        // return getLocalInv(nums, n) == getGlobalInv(nums, 0, n-1);

        return solve_optimal(nums, n);
    }
};