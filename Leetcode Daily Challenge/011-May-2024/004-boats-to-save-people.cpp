// https://leetcode.com/problems/boats-to-save-people/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC : O(N*log(N))
    // SC : O(N)
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people));
        int n     = people.size();
        int boats = 0;
        
        int i = 0, j = n - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i ++, j --;
            }
            else {
                j --;
            }
            boats ++;
        }
        return boats;
    }
};