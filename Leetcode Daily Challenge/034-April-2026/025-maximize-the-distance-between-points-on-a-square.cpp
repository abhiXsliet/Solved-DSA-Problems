// https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/




#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    ll getPointOnStraightLine(int side, int x, int y) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }

    int isPossible(vector<ll> &doubled, int mid, int side, int k, int n) {
        ll perimeter = 4LL * side;

        for (int i = 0; i < n; i ++) {
            int count = 1;
            int idx = i;
            ll lastPos = doubled[idx];

            for (int j = 2; j <= k; j ++) {

                ll target = lastPos + mid;
                
                auto it = lower_bound(begin(doubled) + idx + 1, begin(doubled) + i + n, target);

                if (it == begin(doubled) + i + n) break;

                idx = it - begin(doubled);
                lastPos = doubled[idx];

                count += 1;
            }

            if (count >= k && (doubled[i] + perimeter - lastPos) >= mid) {
                return true;
            }
        }

        return false;
    }
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        ll perimeter = 4LL * side;

        vector<ll> positions(n, 0);
        
        for (int i = 0; i < n; i ++) {
            positions[i] = getPointOnStraightLine(side, points[i][0], points[i][1]);
        }

        sort(begin(positions), end(positions));

        vector<ll> doubled(2*n);

        for (int i = 0; i < n; i ++) {
            doubled[i]     = positions[i];
            doubled[i + n] = positions[i] + perimeter;
        }

        ll low = 0, high = 2*side;
        int ans = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (isPossible(doubled, mid, side, k, n)) {
                ans  = mid;
                low  = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};