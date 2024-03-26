// https://leetcode.com/problems/first-missing-positive/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC = O(N^2) -> TLE
    // SC = O(1)
    int solve_brute_way_1(vector<int>& nums) {
        int n = nums.size();
        int j = 1; 
        while(j <= n+1) {
            int i = 0;
            for(; i<n; i++) {
                if(nums[i] == j) break;
            }
            if(i == n) return j;
            j++;
        }
        return j;
    }

    int solve_brute_way_2(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        while (j <= n + 1) {
            
            for (int i = 0; i < n; i++) {
                if (nums[i] == j) break;
                if (i == n - 1) return j;
            }
            
            j++;
        }
        return j;
    }

    // TC = O(N)
    // SC = O(N)
    int solve_better_way_1(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        int temp = 1;
        for(int i=0; i<n; i++) {
            int ele = nums[i];
            // O(log(N))
            st.insert(ele);
        }
        for(auto& i: st) {
            if(st.find(temp) != st.end()) {
                temp++;
            }
        }
        return temp;
    }

    int solve_better_way_2(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
            st.insert(nums[i]); // O(1)

        int j = 1;

        for (int i = 0; i < n; i++) 
            if (st.find(j) != st.end())
                j++;
            else return j;
        return j;
    }

    // TC => O(N)
    // SC => O(1)
    // Swapping Elements at their correct position
    // 1 -> 0, 2 -> 1, 3 -> 2, 4 -> 3, ...
    int solve_optimal(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            int element = nums[i];
            if(element > 0 && element <= n) {
                //checking if the swapped element is at its correct position
                if(nums[element-1] != element) {
                    swap(nums[element-1], nums[i]);
                    //to check the swapped position again
                    i--;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(i+1 != nums[i])
                return i+1;
        }
        return n+1;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        // return solve_brute_way_1(nums);
        // return solve_brute_way_2(nums);

        // return solve_better_way_1(nums);
        // return solve_better_way_2(nums);

        return solve_optimal(nums);
    }
};