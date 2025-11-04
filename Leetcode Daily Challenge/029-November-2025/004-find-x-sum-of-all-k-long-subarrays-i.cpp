// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(n * k * log(k))
    // SC : O(k)
    typedef pair<int, int> P; //freq, element
    int findTopXSum(unordered_map<int, int>& mp, int x) {
        priority_queue<P, vector<P>, greater<P>> pq; 

        for(auto &it : mp) { 
            pq.push({it.second, it.first});

            if(pq.size() > x) {
                pq.pop(); 
            }
        }

        int sum = 0;
        while(!pq.empty()) { //K
            auto [freq, val] = pq.top(); 
            pq.pop(); //log(k)

            sum += freq*val;
        }

        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int, int> mp;

        vector<int> result;

        int i = 0;
        int j = 0;
       
        while(j < n) {
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                result.push_back(findTopXSum(mp, x));
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return result;
    }
};