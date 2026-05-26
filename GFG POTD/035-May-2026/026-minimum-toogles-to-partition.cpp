// https://www.geeksforgeeks.org/problems/minimum-toogles-to-partition0135/1/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minToggle(vector<int>& arr) {

        int n = arr.size();

        int totalOnes = accumulate(arr.begin(), arr.end(), 0);

        int leftOnes = 0;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            leftOnes += arr[i];

            int rightZeros =
                (n - i - 1) - (totalOnes - leftOnes);

            ans = min(ans, leftOnes + rightZeros);
        }

        // all 0 or all 1
        ans = min(ans,
                  min(totalOnes,
                      n - totalOnes));

        return ans;
    }
};