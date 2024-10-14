// https://leetcode.com/problems/continuous-subarrays/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;

    // TC : O(N * log(N))
    // SC : O(N + N)
    long long approach_1(vector<int>& nums) {
        int n = nums.size();

        priority_queue<P> maxH;
        priority_queue<P, vector<P>, greater<P>> minH;

        int i = 0, j = 0;
        long long ans = 0;
        while (j < n) {
            maxH.push({nums[j], j});
            minH.push({nums[j], j});

            while (maxH.top().first - minH.top().first > 2) {
                i = min(maxH.top().second, minH.top().second) + 1;  // catch
                
                while (maxH.top().second < i) maxH.pop();
                while (minH.top().second < i) minH.pop();
            }

            ans += (j - i + 1);

            j ++;
        }
        return ans;
    }

    // TC : O(N * log(N))
    // SC : O(N)
    long long approach_2(vector<int>& nums) {
        int n = nums.size();

        multiset<int> mst;

        int i = 0, j = 0;
        long long ans = 0;
        while (j < n) {
            mst.insert(nums[j]);

            while (*mst.rbegin() - *mst.begin() > 2) {
                mst.erase(mst.find(nums[i]));
                i ++;
            }

            ans += (j - i + 1);

            j ++;
        }
        return ans;
    }
public:
    long long continuousSubarrays(vector<int>& nums) {
        // return approach_1(nums);     // Using Heaps

        return approach_2(nums);     // Using multiset 
    }
};