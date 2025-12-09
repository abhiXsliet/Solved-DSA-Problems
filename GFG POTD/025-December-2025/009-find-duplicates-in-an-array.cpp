// https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mpp; // 1 --> no. of times
        vector<int> result;
        
        for (int i = 0; i < n; i++) 
            mpp[arr[i]]++;
        
        for(auto& i : mpp) 
            if (i.second > 1) 
                result.push_back(i.first);

        return result;
    }
};