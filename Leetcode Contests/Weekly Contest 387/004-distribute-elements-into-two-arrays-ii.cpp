// https://leetcode.com/contest/weekly-contest-387/problems/distribute-elements-into-two-arrays-ii/



#include <bits/stdc++.h>
using namespace std;

// These are part of the GNU Policy Based Data Structures library
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// ordered_set is defined as a type of red-black tree with pairs of integers as keys
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
private:
    int greaterCount(vector<int> arr, int num) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > num) cnt ++;
        }
        return cnt;
    } 
    // TC : O(N^2)
    // SC : O(N)
    vector<int> solve_brute(vector<int>& nums, int n) {
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        
        for (int i = 2; i < n; i++) {
            int val1 = greaterCount(arr1, nums[i]);
            int val2 = greaterCount(arr2, nums[i]);
            
            if (val1 > val2) arr1.push_back(nums[i]);
            else if (val1 < val2) arr2.push_back(nums[i]);
            else if (val1 == val2) {
                if (arr1.size() < arr2.size())
                    arr1.push_back(nums[i]);
                else if (arr1.size() > arr2.size())
                    arr2.push_back(nums[i]);
                else arr1.push_back(nums[i]);
            }
        }
        // for (auto& n : arr1) cout << n << " ";
        // cout <<endl;
        // for (auto& n : arr2) cout << n << " ";
        // cout << endl;
        vector<int> result(n, 0);
        for (int i = 0; i < arr1.size(); i++) {
            result[i] = arr1[i];
        }
        for (int i = 0; i < arr2.size(); i++) {
            result[i + arr1.size()] = arr2[i];
        }
        return result;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> solve_optimal_1(vector<int>& nums, int n) {
        ordered_set stArr2; 
        ordered_set stArr1;
        
        vector<int> arr1{nums[0]};
        vector<int> arr2{nums[1]};
        
        stArr1.insert({nums[0], 0});    // O(log(N))
        stArr2.insert({nums[1], 1});    // O(log(N))
        
        for (int i = 2; i < n; i++) {
            int cnt1 = stArr1.order_of_key({nums[i] + 1, -1}); // order_of_key => O(log(N))
            int cnt2 = stArr2.order_of_key({nums[i] + 1, -1});
            
            int val1 = arr1.size() - cnt1;
            int val2 = arr2.size() - cnt2;
            
            if (val1 > val2) {
                arr1.push_back(nums[i]);
                stArr1.insert({nums[i], i});
            }
            else if (val1 < val2) {
                arr2.push_back(nums[i]);
                stArr2.insert({nums[i], i});
            }
            else if (val1 == val2) {
                if (arr1.size() <= arr2.size()) {
                    arr1.push_back(nums[i]);
                    stArr1.insert({nums[i], i});
                }
                else if (arr1.size() > arr2.size()) {
                    arr2.push_back(nums[i]);
                    stArr2.insert({nums[i], i});
                }
            }
        }
        
        for (auto& el : arr2) {
            arr1.push_back(el);
        }
        return arr1;
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        // return solve_brute(nums, nums.size());
        
        return solve_optimal_1(nums, nums.size());
    }
};