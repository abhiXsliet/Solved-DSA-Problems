// https://leetcode.com/problems/two-sum/



#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

// Time Complexity => O(N^2)
// Space Complexity => O(N)
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i]+nums[j] == target) {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
            }
        }
    }
    return ans;
}

// Time Complexity => O(N)
// Space Complexity => O(N)
vector<int> twoSumOptimized(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int>result;
    for(int i=0; i<n; i++) {
        int ele = nums[i];
        int requirement = target - ele;
        if(result.find(requirement) != result.end()) {
            return {i, result[requirement]};
        }
        result[ele] = i;
    }
    return {};
}

int main() {
    vector<int> nums;
    nums.insert(nums.end(), {1, 3, 4, 8, 9});
    
    // vector<int>ans = twoSum(nums, 11);

    vector<int> ans = twoSumOptimized(nums, 11);
    for(int i=0; i<ans.size(); i++) 
        cout << ans[i] << " ";


    return 0;
}