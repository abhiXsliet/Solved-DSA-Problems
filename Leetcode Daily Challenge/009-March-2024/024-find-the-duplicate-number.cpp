// https://leetcode.com/problems/find-the-duplicate-number/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O( N * log(N) )
    // SC = O( 1 )
    int solve_brute(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;

        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (i + 1 < n && nums[i] == nums[i + 1])
                ans = nums[i];

        return ans;
    }

    // TC = O( N )
    // SC = O( 1 )
    int solve_better_1(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int idx  = nums[i] % n;
            nums[idx] += n;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] / n  > 1) 
                return i;
        }
        return -1;
    }

    // TC = O( N )
    // SC = O( 1 )
    int solve_better_2(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]);

            if (nums[idx] > 0) {
                nums[idx] *= -1;
            }
            else {
                return abs(nums[i]);
            }
        }
        return -1;
    }

    // TC = O( N )
    // SC = O( 1 )
    int solve_optimal(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Handling if starting element is same 
        // because if cycle detected in the starting leads to breaking out of loop
        slow = nums[slow];
        fast = nums[nums[fast]];

        // detecting cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // take the slow pointer to the start
        slow = nums[0];

        // move the slow and fast by one step till they not meet
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        // return either slow or fast
        return slow;
    }
public:
    int findDuplicate(vector<int>& nums) {
        // return solve_brute(nums);
        // return solve_better_1(nums);
        // return solve_better_2(nums);
        
        return solve_optimal(nums);     // Array Not getting Modified
    }
};