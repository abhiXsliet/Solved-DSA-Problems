// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1


#include <bits/stdc++.h>
using namespace std;

// TC = O(N^2)
// SC = O(1)
vector<int> brute_leader(vector<int>& nums, int n) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        bool leader = true;
        for(int j = i+1 ; j < n ; j++) {
            if(nums[i] < nums[j]) {
                leader = false;
                break;
            }
        }
        if(leader) {
            result.push_back(nums[i]);
        }
    }
    return result;
}

// TC = O(N)
// SC = O(1)
vector<int> optimal_leader(vector<int>& nums, int n) {
    vector<int> result;
    int maxi = INT_MIN;
    for(int i = nums.size() - 1; i >= 0; i--) {
        if(nums[i] > maxi)  {
            maxi = max(maxi, nums[i]);
            result.push_back(nums[i]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {16, 17, 4, 2, 5, 2};
    vector<int> ans = brute_leader(nums, nums.size());
    cout << "\nPrinting Leaders using brute force => ";
    for(auto& i : ans) {
        cout << i << " ";
    }

    cout << endl;

    ans = optimal_leader(nums, nums.size());
    cout << "Printing Leaders using optimal => ";
    for(auto& i : ans) {
        cout <<  i << " ";
    }

    cout << endl;
    cout << endl;
    return 0;
}