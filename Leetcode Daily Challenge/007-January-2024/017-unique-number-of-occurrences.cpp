// https://leetcode.com/problems/unique-number-of-occurrences/



#include <bits/stdc++.h>    
using namespace std;

class Solution {
private:
    // TC : O(N)
    // SC : O(N)
    bool solve_brute(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int num : arr) {
            freq[num]++;
        }

        unordered_set<int> counts;
        for(auto &pair: freq) {
            if(counts.find(pair.second) != counts.end()) {
                return false;
            }
            counts.insert(pair.second);
        }
        return true;
    }

    // TC : O(N) + O(2001 * log(2001)) ~= O(N)
    // SC : O(2001) ~= O(1)
    bool solve_optimal(vector<int>& arr) {
        vector<int> vec(2001, 0);

        for (int num : arr) {
            vec[num + 1000] ++;
        }

        sort(begin(vec), end(vec));

        for (int i = 1; i < 2001; i++) {
            if (vec[i] != 0 && vec[i] == vec[i - 1])
                return false;
        }
        return true;
    }
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // return solve_brute(arr);

        return solve_optimal(arr);
    }
};
