// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> minMaxCandy(vector<int>& candies, int K) {
        int N = candies.size();
        
        sort(begin(candies), end(candies));
        
        int mini = 0;
        int buy = 0;
        int free = N-1;
        
        while(buy <= free) {
            mini += candies[buy];
            buy++;
            free -= K;
        }
        
        int maxi = 0;
        buy = N-1;
        free = 0;
        
        while(free <= buy) {
            maxi += candies[buy];
            buy--;
            free += K;
        }
        
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};