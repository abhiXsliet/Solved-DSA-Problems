// https://leetcode.com/problems/contains-duplicate/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Time Complexity => O(Nlog(N))
    // // Space Complexity => O(1)
    // bool containsDuplicate(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int i = 0;
    //     while(i<nums.size()-1) {
    //         int ele = nums[i];
    //         if(nums[i] == nums[i+1])
    //             return true;
    //         i++;
    //     }
    //     return false;
    // }



    // Time Complexity => O(N)
    // Space Complexity => O(N)
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int, int> res;
        // for(int i=0; i<nums.size(); i++) {
        //     int ele = nums[i];
        //     if(res.find(ele) != res.end()) {
        //         return true;
        //     }
        //     res[ele] = i;
        // }
        // return false;

        // set stores a key only
        unordered_set<int> store;
        for(int i=0; i<nums.size(); i++) {
            int ele = nums[i];
            if(store.find(ele) != store.end())
                return true;
            store.insert(ele);
        }
        return false;
    }
};