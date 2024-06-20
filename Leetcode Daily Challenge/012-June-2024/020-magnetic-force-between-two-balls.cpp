// https://leetcode.com/problems/magnetic-force-between-two-balls/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N)
    bool canWePlace(vector<int>& position, int m, int d) {
        int n    = position.size();
        int last = position[0];
        int ball = 1;
        for (int i = 1; i < n; i ++) {
            if (position[i] - last >= d) {
                ball ++;
                last = position[i];
            }
            if (ball >= m) return true;
        }
        return false;
    }

    // TC : O(|maxi - mini| * N) Where N = Size of position array
    // SC : O(1)        
    // TLE since |maxi - mini| could be 10^9 and N could be 10^5 => at worst : 10^14 
    int brute(vector<int>& position, int m) {   
        sort(begin(position), end(position));

        int maxi  = *max_element(begin(position), end(position));
        int mini  = *min_element(begin(position), end(position));
        int limit =  maxi - mini;

        for (int d = 1; d <= limit + 1; d ++) {
            if (!canWePlace(position, m, d))    {
                return (d - 1);
            }
        }

        return -1;
    }

    // TC : O(N*log(maxi)) Where N = Size of Position Array 
    //                     & maxi is the maximum element of position array
    // SC : O(1)
    int optimal(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int low = 0, high = *max_element(begin(position), end(position));
        int minMaxForce = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (canWePlace(position, m, mid)) {
                minMaxForce = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return minMaxForce;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        // return brute(position, m);

        return optimal(position, m);
    }
};