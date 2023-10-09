// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    int firstOccurance(vector<int>& arr, int key){
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;

        while(s<=e){
            int mid = (s + (e - s)/2);
            if(arr[mid] == key){
                ans = mid ;
                e = mid - 1;
            }
            else if(arr[mid]>key){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }        
        }
        return ans;
    }

    int lastOccurance(vector<int>& arr, int key){
        int s = 0; 
        int e = arr.size() - 1;
        int ans = -1;
        
        while (s<=e)
        {
            int mid = (s + (e - s)/2);
            if(arr[mid]==key){
                ans = mid;
                s = mid + 1;
            }
            else if(arr[mid]<key){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }        
        }
        return ans;
    }

    int findOcc(vector<int>& nums, int target, bool flag) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                if (flag == 0) {
                    ans = mid;
                    high = mid - 1;
                }
                else {
                    ans = mid;
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    // TC = O(N * log(N)), SC = O(1)
    vector<int> solve_1(vector<int>& nums, int target) {
        vector<int>result;
        int first = firstOccurance(nums, target);
        int second = lastOccurance(nums, target);
        
        if(first == -1) {
            result.push_back(-1);
            result.push_back(-1);
        }else{
            result.push_back(first);
            result.push_back(second);
        }
        return result;
    }

    // TC = O(N * log(N)), SC = O(1)
    vector<int> solve_2(vector<int>& nums, int target) {
        vector<int> result;
        int first  = findOcc(nums, target, 0);
        int second = findOcc(nums, target, 1);

        if (first == -1) {
            result.push_back(-1);
            result.push_back(-1);
        }
        else {
            result.push_back(first);
            result.push_back(second);
        }

        return result;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // return solve_1(nums, target);

        return solve_2(nums, target);
    }
};