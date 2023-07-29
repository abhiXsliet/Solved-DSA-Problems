// https://leetcode.com/problems/first-missing-positive/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        // // TC = O(N^2) -> TLE
        // // SC = O(1)
        // int n = nums.size();
        // int j = 1; 
        // while(j <= n+1) {
        //     int i = 0;
        //     for(; i<n; i++) {
        //         if(nums[i] == j) break;
        //     }
        //     if(i == n) return j;
        //     j++;
        // }
        // return j;



        // // TC = O(N)
        // // SC = O(N)
        // set<int>st;
        // int n = nums.size();
        // int temp = 1;
        // for(int i=0; i<n; i++) {
        //     int ele = nums[i];
        //     st.insert(ele);
        // }
        // for(auto& i: st) {
        //     if(st.find(temp) != st.end()) {
        //         temp++;
        //     }
        // }
        // return temp;



        // TC => O(N)
        // SC => O(1)
        int n = nums.size();
        //logic for swapping elements at its correct position
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
};