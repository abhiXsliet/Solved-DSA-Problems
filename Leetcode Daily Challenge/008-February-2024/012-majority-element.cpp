// https://leetcode.com/problems/majority-element/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int>& nums, int n) {
        int cnt         = 0;
        int majorityEle = NULL;
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                cnt = 1;
                majorityEle = nums[i];
            } else if( majorityEle == nums[i] ) {
                cnt++;
            } else {
                cnt--;
            }
        }
        // given that majority element always exists
        // so no need to verify the freq of majority element > n/2
        return majorityEle;
    }

    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& nums, int n) {
        int cnt         = 0;
        int majorityEle = NULL;
        
        for(int i = 0; i < n; i++) {

            if( majorityEle == nums[i] ) {
                cnt++;
            } 
            else if (cnt == 0){
                cnt         = 1;
                majorityEle = nums[i];
            }
            else cnt --;
        }
        // given that majority element always exists
        // so no need to verify the freq of majority element > n/2
        return majorityEle;
    }
public:
    int majorityElement(vector<int>& nums) {
        // Brute Force -> use Hashmap -> Time & space complexity will be O(N)

        // return approach_1(nums, nums.size());

        return approach_2(nums, nums.size());
    }
};