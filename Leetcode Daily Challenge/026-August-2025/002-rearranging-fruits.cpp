// https://leetcode.com/problems/rearranging-fruits/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    // TC : O(N*log(N)) 
    // SC : O(N)
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mpp;
        int minEle = INT_MAX;

        for (int &val : basket1) {
            mpp[val] ++;
            minEle = min(minEle, val);
        }    
        for (int &val : basket2) {
            mpp[val] --;
            minEle = min(minEle, val);
        }

        vector<int> store;  // stores only those elements which needs to be swapped
        for (auto &it : mpp) {
            int ele  = it.first;
            int freq = it.second;

            if (!freq) continue;

            if (freq % 2) return -1;

            for (int t = 1; t <= abs(freq) / 2; t ++) {
                store.push_back(ele);
            }
        }

        // sort(begin(store), end(store));
        
        // Using nth_element for partial sorting is more efficient than full sort (O(n log n)); 
        // it runs in linear time on average.
        nth_element(begin(store), begin(store) + store.size() / 2, end(store));
        
        ll result = 0;
        for (int i = 0; i < store.size() / 2; i ++) {
            result += min(store[i], minEle * 2);
        }
        return result;
    }
};